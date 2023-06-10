// Redes de Computadoras - Curso 1er Semestre 2022
// Tecnologo en Informatica FIng - CETP
//
// Entrega 2  - Programacion con Sockets
// Sistema basico de Mensajeria 

// Integrantes:
//	Detallar aqui, nombre, apellido y documento de todos los integrantes del grupo.

#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <arpa/inet.h> // para inet_Addr, etc
#include <netdb.h> // estrucrutas
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h> 
#include <sys/wait.h>
#include <sys/signal.h>
#include <ctype.h> 
#include <iostream>
#include "md5.h"

#define MAX_LARGO_MENSAJE 255
#define MAX_USER 50
#define BACKLOG 3

using namespace std;

int fd, fd1, fd2, fd3;


void manejadorSenhales (int signal){
// Manejador de las senhales.
// Aca se debe implementar la accion a realizar cuando se recibe la senhal
// Deberia haber un manejador de senhales para cada hijo si hacen cosas distintas
	if (signal == SIGINT){
		cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGINT CTRL+C recibido\33[00m\n"; 
	}
	if (signal == SIGTERM){
		cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGTERM Terminacion de programa\33[00m\n";
	}
	if (signal == SIGSEGV){
		cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGSEGV violacion de segmento\33[00m\n";
	}
	if (signal == SIGCHLD){
		cout << "\33[46m\33[31m[" << "]" << " SIGCHLD \33[00m\n";
	}
	if (signal == SIGPIPE){
		cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGPIPE \33[00m\n";
	}
	if (signal == SIGKILL){
		cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGKILL \33[00m\n";
	}
	close(fd);
	close(fd1);
	close(fd2);
	close(fd3);
	exit(1);
}

void resetString (char * & s){
// Resetea un string.
	s[0] = '\0';
}

char * agregarCero(char * cad,int num){
// Chequea si el num es < 10 y me devuelve un string con el '0'
// concatenado con num en dicho caso
	char * aux = new char[25];
	resetString(aux);
	strcat(aux,"0");
	sprintf(cad,"%d",num);
	if(num<10){
		strcat(aux,cad);
		return aux;
	}
	else{
		delete[] aux;
		return cad;
	}
}


char * getTiempo(){
// Obtiene la fecha y hora local y la almacena en un string
// con formato DD/MM/YYYY-hh:mm:ss
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	int hh = timeinfo -> tm_hour;
	int mm = timeinfo -> tm_min;
	int ss = timeinfo -> tm_sec;
	int DD = timeinfo -> tm_mday;
	int MM = (timeinfo -> tm_mon) + 1; //xq enero = 0
	int YYYY = (timeinfo -> tm_year) + 1900 ; //xq el año es desde 1900
	char * s = new char[19];
	resetString(s);
	char * cad = new char[25];
	resetString(cad);
	//chequeo si alguna es menor q 10 para concatenarle un '0'
	strcat(s,"[");
	cad = agregarCero(cad,YYYY);
	strcat(s,cad);
	strcat(s,".");
	cad = agregarCero(cad,MM);
	strcat(s,cad);
	strcat(s,".");
	cad = agregarCero(cad,DD);
	strcat(s,cad);
	strcat(s," ");
	cad = agregarCero(cad,hh);
	strcat(s,cad);
	strcat(s,":");
	cad = agregarCero(cad,mm);
	strcat(s,cad);
	strcat(s,":");
	cad = agregarCero(cad,ss);
	strcat(s,cad);
	strcat(s,"]");
	return s;
}

int main(int argc, char * argv[]){
// En argc viene la cantidad de argumentos que se pasan,
// si se llama solo al programa, el nombre es el argumento 0
// En nuestro caso:
//      - argv[0] es el string "mensajeria", puede cambiar si se llama con otro path.
//      - argv[1] es el puerto de escucha de mensajeria.
//      - argv[2] es el ip del servidor de autenticacion.
//      - argv[3] es el puerto del servidor de autenticacion.

	if (argc < 4){
		cout << "\33[46m\33[31m[ERROR]:" << " Faltan argumentos: port, ipAuth, portAuth.\33[00m\n";
		exit (1);
	}

	// Estructuras para el manejo de Senhales
	// Deberia haber un manejador de senhales para cada hijo si hacen cosas distintas
	// *********************************
	struct sigaction sa;
	memset (&sa, 0, sizeof (sa));
	sa.sa_handler = &manejadorSenhales;

	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGTERM, &sa, NULL);
	sigaction(SIGPIPE, &sa, NULL);
	sigaction(SIGSEGV, &sa, NULL);
	sigaction(SIGKILL, &sa, NULL);
	signal(SIGALRM, SIG_IGN);
	// **********************************
	
	cout << "\33[34mRedes de Computadoras 2022\33[39m: Sistema de Mensajeria.\nEscuchando en el puerto " << argv[1] << ".\nProceso de pid: " << getpid() << ".\n";
	
	// Antes de iniciar el programa de mensajeria debe autenticarse
	// como especifica la letra
	
	struct sockaddr_in auth;
	struct hostent *he;      // host entry
	
	if ((he=gethostbyname(argv[2]))==NULL){       
    	// llamada a gethostbyname() 
		printf("No se encuentra el servidor de autenticacion\n");
		exit(-1);
	}
	
	auth.sin_family = AF_INET;
	auth.sin_port = htons(atoi(argv[3])); //Puerto autenticacion
	auth.sin_addr = *((struct in_addr *)he->h_addr); // Escribe la dir resuelta por gethostbyname()  
	bzero(&(auth.sin_zero),8);	// Completa con ceros la estructura


	if ((fd=socket(AF_INET, SOCK_STREAM, 0))==-1){  
      	// llamada a socket() 
      	printf("socket() error\n");
      	exit(-1);
   	}
   	
   	
   	char usuario[MAX_USER];
   	char clave[MAX_USER];
   	char clavemd5[MAX_USER];
   	char buf[MAX_LARGO_MENSAJE];
   	buf[0] = '\0';
   	
   	cout << "Usuario: ";
   	cin >> usuario;
    	   	
   	cout << "Clave: ";
   	cin >> clave;
 
	cout << buf << endl;
   	getchar();
	if(connect(fd, (struct sockaddr *)&auth, sizeof(struct sockaddr))== -1){ 
      	// llamada a connect() 
      	printf("connect auth() error\n");
  		exit(-1);
	}
	int numbytes;
	
	if ((numbytes=recv(fd,buf, MAX_LARGO_MENSAJE,0)) == -1){  
     	// llamada a recv() 
      	printf("Error en recv() \n");
   		exit(-1);
   	}

   	buf[numbytes- 2]='\0';

   	if (strcmp (buf, "Redes 2022 - Laboratorio - Autenticacion de Usuarios") != 0){  
 		printf("Servidor de autenticacion incorrecto\n");  		
      	exit(-1);
   	}
   	
 	strcpy(buf,"");
 	strcat(buf, usuario);
   	strcat(buf, "-");
   	strcpy(clavemd5, md5(clave).c_str());
	strcat(buf, clavemd5);
	strcat(buf, "\r\n");
   	
   	send(fd, buf, strlen(buf), 0); //Envia el usuario y la clave
  	
   	if ((numbytes=recv(fd, buf, MAX_LARGO_MENSAJE,0)) == -1){  
     	// llamada a recv() 
      	printf("Error en recv() \n");
   		exit(-1);
   	}
   	
   	buf[numbytes- 2]='\0';
   	  	
	if (strcmp(buf, "NO") == 0){
   		printf("Usuario o clave incorrecta\n");
   		exit(-1);
    	
   	} else if (strcmp(buf, "SI") != 0){
     	printf("Error en la autenticacion\n");
     	exit(-1);
    }

	if ((numbytes=recv(fd, buf, MAX_LARGO_MENSAJE,0)) == -1){  
     	// llamada a recv() 
      	printf("Error en recv() \n");
      	exit(-1);
   	}
   	
    buf[numbytes- 2]='\0';
    	
    if ((numbytes=recv(fd, buf, MAX_LARGO_MENSAJE,0)) == -1){  
      // llamada a recv()
   		printf("Error en recv() \n");
      	exit(-1);
   	}
   	
    buf[numbytes- 2]='\0';
    	
    cout << "Bienvenido " << buf << endl;
   
    
	// Una vez autenticado puede comenzar a recibir y empezar el mensajes y archivos.
	// Para esto se debe bifircar el programa.
	// Es indistinto si el padre transmite y el hijo recibe, o viceversa, lo que si
	// al ser distintos porcesos, van a tener distinto pid.
	// Familiarizarse con los comandos de UNIX ps, ps -as, kill, etc.

	int pid = fork();
	
	if (pid < 0){
		cout << "\33[46m\33[31m[ERROR]:" << " Imposible Bifurcar.\33[00m\n";
		exit (1);
	}
	
	if (pid == 0){
	//HIJO
	//RECEPTOR

		printf("\33[34mRx\33[39m: Iniciada parte que recepciona mensajes. Pid %d\n", getpid());
		
		fd1 = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); //Crea socket TCP 
		if (fd1 < 0){
			printf("error en socket()\n");
			exit(-1);
		}
		
		cout << "R: 1 - " << argv[1] << " - "  << endl;		
		struct sockaddr_in server; /* para la información de la dirección del servidor */			
						
		server.sin_family = AF_INET;
		server.sin_port = htons(atoi(argv[1])); //Puerto "escucha"
		server.sin_addr.s_addr = INADDR_ANY; // Escucha por todas las direcciones de red del host
		bzero(&(server.sin_zero),8);	// Completa con ceros la estructura
		cout << "R: 2" << endl;		
		
		int error = bind(fd1,(struct sockaddr*)&server, sizeof(struct sockaddr)); 
		if (error < 0){
			printf("error en bind() \n");
			exit(-1);
		}
		/*cout << "R: 3" << endl;		
		
		error = listen(fd1, BACKLOG);  
		if (error < 0){
			printf("error en listen()\n");
			exit(-1);
		}
		cout << "R: 4 antes accept" << endl;		
	
		char bufMsjReceptor [MAX_LARGO_MENSAJE];
		int numbytesMsj;
		unsigned int sin_size = sizeof(struct sockaddr_in); // Para pasarle el tamaño
		
		fd2 = accept(fd1,(struct sockaddr *)&client, &sin_size);
		cout << "R: 5 despues de accept" << endl;		

		if (fd2 < 0){
			printf("error en socket()\n");
			exit(-1);
		}
		*/	
		while (true){
			cout << "R: inicio while" << endl;
			int numbytesMsj;
			char bufMsjReceptor [MAX_LARGO_MENSAJE];
			unsigned int size = sizeof(struct sockaddr);
			struct sockaddr_in client; /* para la información de la dirección del cliente */
			
			
			printf("R: esperando mensaje...\n");
			
			numbytesMsj = recvfrom(fd1, (char  *)&bufMsjReceptor, MAX_LARGO_MENSAJE, 0, (struct sockaddr *)&client, &size);
			if (numbytesMsj < 0){ 
				printf ("error en recv()\n");
				exit(-1);
			}
			
			cout << "R: mensaje recibido!!!" << bufMsjReceptor<< endl;
			printf(" > %s %s %s dice: ", getTiempo (),inet_ntoa(client.sin_addr), "usuario");
			
			bufMsjReceptor[numbytesMsj] = '\0';
			printf("%s\n", bufMsjReceptor);
			
			sleep(1);
					// Incluir el codigo de la recepcion de mensajeria y archivos.
		}
		
	}
		
	if (pid > 0){
	//PADRE
	//EMISOR
		printf("\33[34mTx\33[39m: Iniciada parte que transmite mensajes. Pid %d\n", getpid());
		
		struct sockaddr_in server; //Informacion sobre la direccion del servidor		
		cout << "E: 1" << endl;		
		sleep(1);
			
		/*resuelve el dns*/
/*		if ((he=gethostbyname(argv[2]))==NULL){
			gethostbyname() 
			printf("gethostbyname() error\n");
			exit(-1);
		}*/
		cout << "E: 2" << endl;		
		
		fd3 = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); 
		if (fd3 < 0){
			printf("error en client socket()\n");
			exit(-1);
		}
		cout << "E: 3" << endl;		

	
		/*int error = connect(fd3, (struct sockaddr *)&server, sizeof(struct sockaddr));
		if (error < 0 ){ 
			printf("connect client() error\n");
			exit(-1);
		}
		cout << "E: 4 NO client() error" << endl;		
		*/
		
		while (true){
			char bufMsjEmisor[MAX_LARGO_MENSAJE];
			char bufMsjEmisorCompleto[MAX_LARGO_MENSAJE];
			struct hostent *he; //Estructura que recibira informacion sobre el nodo remoto  
			
		   	char ipUsuarioReceptor[MAX_USER];
			bufMsjEmisor[0] = '\0';
			cout << "E: antes de leer mensajeEmisor" << endl;
			
			cin >> ipUsuarioReceptor;
			cin.getline (bufMsjEmisor, MAX_LARGO_MENSAJE); //Para que lea el salto de linea
			//ip mensaje
			
			cout << "ipUsuarioReceptor: -" << ipUsuarioReceptor << "-" << endl;			
			cout << "bufMsjEmisor: -" << bufMsjEmisor << "-" << endl;
			he=gethostbyname(ipUsuarioReceptor);
			server.sin_family = AF_INET;        
			server.sin_port = htons(atoi(argv[1])); // Puerto a conectarse
			server.sin_addr = *((struct in_addr *)he->h_addr);   // ip o dominio a conectarse
			bzero(&(server.sin_zero),8); 			// Completa con ceros la estructura


			int i;
			for (i = 0; i <= 255; i++){
				if ( bufMsjEmisor[i] == '\n' ){
					bufMsjEmisor[i] = '\0';
				}
			}
			cout << "E: 5 lei mensajeEmisor" << endl;	
				
			strcat(bufMsjEmisorCompleto,"myIp");
			strcat(bufMsjEmisorCompleto," ");
			strcat(bufMsjEmisorCompleto,usuario);
			strcat(bufMsjEmisorCompleto," ");
			strcat(bufMsjEmisorCompleto,bufMsjEmisor);
				
			send(fd3, bufMsjEmisorCompleto, strlen(bufMsjEmisorCompleto), 0);
			cout << "E: 7 mande mensajeEmisor, estaria esperando respuesta (o no)" << endl;		


			
			//Evalua si el cliente quiere hacer un broadcast
			//if (bufMSjEmisor[0] == '*'{
/*				int pidBroadcast = fork();	
				
				if (pidBroadcast < 0){
					cout << "\33[46m\33[31m[ERROR]:" << " Imposible Bifurcar.\33[00m\n";
					exit (1);
				}
				
				if (pidBroadcast == 0){
				//Receptor
					int fd4 = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); // Creo socket UDP
					if (fd4 < 0){
						printf("error en socket broadcast()\n");
						exit(-1);
					}
					
					char broadcast = 1;
					
					//Le doy permisos para hacer broadcast al socket
					if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast)) < 0){

        				cout<<"Error in setting Broadcast option";
						exit(-1);
					}
					
					struct sockaddr_in server;
					struct sockaddr_in client;
					
					server.sin_family = AF_INET;        
					server.sin_port = 5555; 				// Puerto de recepción.
					server.sin_addr.s_addr = INADDR_ANY;    // Escucha por todas las direcciones de red del host
					bzero(&(server.sin_zero),8); 			// Completa con ceros la estructura 	
					
					int error = bind(fd1,(struct sockaddr*)&server, sizeof(struct sockaddr));
					if (error < 0){
					printf("error en bind() \n");
					exit(-1);
				}
					
				} 
				
							
			}
			
			int i;
			for (i = 0; i <= 255; i++){
				if ( bufMsjEmisor[i] == '\n' ){
					bufMsjEmisor[i] = '\0';
				}
			}
			cout << "E: 5 lei mensajeEmisor" << endl;	
	

			//strcat (bufMsjEmisor, mensajeEmisor);
			
			cout << "E: 6 concatene mensajeEmisor" << endl;		

			
			//send((fd3," > %s %s %s dice:\r\n",getTiempo (),inet_ntoa(client.sin_addr), buf, 0);
			
			send(fd3, bufMsjEmisor, strlen(bufMsjEmisor), 0);
			cout << "E: 7 mande mensajeEmisor, estaria esperando respuesta (o no)" << endl;		
*/

///MENSAJE RESPUESTA DE SERV
/*			int numbytesMsj = recv(fd3, bufMsjEmisor, MAX_LARGO_MENSAJE, 0);
					
			cout << "E: 8 recibi mensaje de respuesta" << endl;		
	
			if(numbytesMsj < 0){  
				printf("Error en recv() \n");
				exit(-1);
			}
			cout << "E: 9 recibi mensaje de respuesta OK" << endl;
			bufMsjEmisor[numbytesMsj] = '\0';	
					*/
			sleep(1);
			// Leer de la entrada estandar e incluir
			// el codigo de la emision de mensajeria y archivos.
		}
	}
}
