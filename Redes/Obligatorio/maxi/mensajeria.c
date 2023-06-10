
// Redes de Computadoras - Curso 1er Semestre 2015
// Tecnologo en Informatica FIng - CETP
//
// Entrega 2  - Programacion con Sockets
// Sistema básico de Mensajería

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctime>
#include <time.h>
#define MAX_USR_PWD 63
#define MAX_LARGO_MENSAJE 255
#define MAX_LARGO_ARCHIVO 65535
#define BACKLOG 10 // El número de conexiones permitidas

using namespace std;

int fd, fd2, fdbro; 
FILE * pf;
bool padre = false;

void manejadorSenhales (int signal){
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


char * fechayhora(){
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

int main(int argc, char * argv[])
// En argc viene la cantidad de argumentos que se pasan,
// si se llama solo al programa, el nombre es el argumento 0
// En nuestro caso:
//      - argv[0] es el string "mensajeria", puede cambiar si se llama con otro path.
//      - argv[1] es el puerto de escucha de mensajeria.
//      - argv[2] es el ip del servidor de autenticacion.
//      - argv[3] es el puerto del servidor de autenticación.
{
	if (argc < 4)
	{
			cout << "\33[46m\33[31m[ERROR]:" << " Faltan argumentos: port, ipAuth, portAuth.\33[00m\n";
			exit(-1);
	}

	// Estructuras para el manejo de Senhales
	// Deberia haber un manejador de señales para cada hijo si hacen cosas distintas
	// *********************************
    struct sigaction sa;
	memset (&sa, 0, sizeof (sa));
	sa.sa_handler = &manejadorSenhales;

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGTERM, &sa, NULL);
	sigaction(SIGPIPE, &sa, NULL);
	sigaction(SIGSEGV, &sa, NULL);
	sigaction(SIGKILL, &sa, NULL);
	signal(SIGALRM, SIG_IGN);


	cout << "\33[34mRedes de Computadoras 2014\33[39m: Sistema de Mensajeria.\nEscuchando en el puerto " << argv[1] << ".\nProceso de pid: " << getpid() << ".\n";


	// ******************
	// VARIABLES
	
	struct sockaddr_in server, client;
	char ipreceptor[30];
	char mensaje[MAX_LARGO_MENSAJE];
	char fecha[18];
	const char* fechaChar;
	unsigned int sin_size;

	// ******************
	// AUTENTICACION

	// Crea socket tcp
	fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0){
	    printf("ERROR: socket()");
	    exit(-1);
	}
	
	// Crea el server
	server.sin_family = AF_INET;		
    server.sin_port = htons(atoi(argv[3]));	
    server.sin_addr.s_addr = inet_addr(argv[2]);
    bzero(&(server.sin_zero),8);
	
	// connect() server
    if (connect(fd, (struct sockaddr *)&server, sizeof(struct sockaddr))==-1){
		printf("ERROR: connect()\n");
		exit(-1);
    }
	
	int numbytes = 0;
	char buf[MAX_LARGO_MENSAJE]; 	
	buf[0] = '\0';
	
	// recv() mensaje de bienvenida
    if ((numbytes = recv(fd, buf, MAX_LARGO_MENSAJE, 0)) == -1){
		printf("ERROR: recv()\n");
		exit(-1);
    }

	// Guarda usuario y password
	char usuario[MAX_USR_PWD];
	char clave[MAX_USR_PWD];
	
    cout << "Usuario: ";
    cin >> usuario;
    cout << "Clave: ";
    cin >> clave;
	
	char com[100];// echo para generar md5
  	com[0] = '\0';
	
	// genera la clave md5
	strcpy(com,"echo ");
    strcat(com,clave);
    strcat(com," | md5sum > usuarios");
    system(com);
	
	// Abre el archivo de usuarios
    if ((pf=fopen("usuarios","r"))==NULL){
        printf("ERROR: fopen()\n");
        exit(-1);
    }
	
	char usermd5[33]; // password en md5
	usermd5[0] = '\0';
	//Lee la primera linea y lo guarda en usermd5
    fscanf(pf,"%s",usermd5);
    fclose(pf);
    strcat(usermd5,"\0");
    system("rm usuarios");
	
	// Arma usuario-clave en el buffer
	buf[0] = '\0';
	strcpy(buf,usuario);
    strcat(buf,"-");
    strcat(buf,usermd5);
    strcat(buf,"\0");
	
    // Envia el buffer al servidor de autenticacion
	if (send(fd, buf, strlen(buf) + 2, 0)==-1){
        cout << "ERROR: Imposible enviar datos al servidor de Autenticacion\n";
        exit(-1);
    }
    numbytes=0;
    buf[0] = '\0';
	
	//Valida respuesta del servidor
    if ((numbytes = recv(fd, buf, MAX_LARGO_MENSAJE, 0)) == -1){
       cout << "ERROR: recv() auth\n";
       exit(-1);
	}
	
	buf[numbytes-2]='\0';
	
	if (strcmp(buf,"NO") == 0){
	    cout << "ERROR: Usuario o contraseña incorrecta\n";
	    exit(-1);
	}
	
    numbytes=0;
    buf[0] = '\0';
	//Recibe mensaje de bienvenida
    if ((numbytes=recv(fd, buf, MAX_LARGO_MENSAJE, 0)) == -1){
       cout << "ERROR: recv() bienvenida\n";
       exit(-1);
	}
	buf[numbytes-2]='\0';
	
	cout << "Bienvenido " << buf << endl;
	close(fd);

	// **************************************************************
	
	// Una vez autenticado puede comenzar a recibir y empezar el mensajes y archivos.
	// Para esto se debe bifircar el programa.
	// Es indistinto si el padre transmite y el hijo recibe, o viceversa, lo que si
	// al ser distintos porcesos, van a tener distinto pid.
	// Familiarizarse con los comandos de UNIX ps, ps -as, kill, etc.
	
	int pid, pid2;
	pid = fork();
	
    if (pid < 0){
		cout << "\33[46m\33[31m[ERROR]:" << " Imposible Bifurcar.\33[00m\n";
		exit(-1);
   	}
   

    if (pid == 0) { 
	//Receptor
		printf("\33[34mRx\33[39m: Iniciada parte que recepciona mensajes. Pid %d\n", getpid());

		padre = false;
		
		// pid2 recibe tcp
			pid2 = fork();
			if (pid2<0){
				printf("ERROR: error en fork()\n");
				exit(-1);
			}
			
			if (pid2 == 0){ // servidor recibe tcp
			
				server.sin_family = AF_INET;
				server.sin_port = htons(atoi(argv[1])); //Puerto "escucha"
				server.sin_addr.s_addr = INADDR_ANY; //Escucha por todas las direcciones
				bzero(&(server.sin_zero),8); // Completa la estructura con ceros
				
				// Crea socket tcp
				fd = socket(AF_INET, SOCK_STREAM, 0);
				if (fd < 0 ){
					printf("ERROR: socket() tcp\n");
					exit(-1);
				}
				
				// Bind
				
				numbytes = bind(fd,(struct sockaddr*)&server,sizeof(struct sockaddr));
				if (error < 0) {
					printf("ERROR: bind() tcp\n");
					exit(-1);
				}
				
				// Escucha hasta BACKLOG conexiones
				error = listen(fd, BACKLOG);
				if (error < 0){
					printf("ERROR: listen()\n");
					exit(-1);
				}
				
				sin_size = sizeof(struct sockaddr_in);
				
				// Permanece recibiendo mensajes
				while (true){
						
					fd2 = accept(fd,(struct sockaddr *)&client, &sin_size);
					if (fd2 < 0){
						printf("ERROR: accept()\n");
						exit(-1);
					}
					
					buf[0] = '\0';
					numbytes = 0;
					
					numbytes = recv(fd2, buf, MAX_LARGO_MENSAJE, 0);
					if (numbytes < 0){
						printf("ERROR: recv() recepcion\n");
						exit(-1);
					}
					
					fecha[0] = '\0';
					fechaChar = fechayhora();
					strcpy(fecha, fechaChar);
					buf[numbytes-2]='\0';
					
					// Imprime el mensaje en pantalla
					cout << "[" << fecha << "] " << inet_ntoa(client.sin_addr) << " " << buf << endl;
					close(fd2);
				}
				// Cerramos el socket
				close(fd);
			}
			if (pid2 > 0){ // servidor recibe udp
			
				server.sin_family = AF_INET;
				server.sin_port = htons(atoi(argv[1]+1));
				server.sin_addr.s_addr = INADDR_ANY;
				bzero(&(server.sin_zero),8);
				sin_size = sizeof(struct sockaddr_in);
				
				while (true){
					
					//Crea socket udp
					fdbro = socket(AF_INET, SOCK_DGRAM, 0);
					if (fdbro < 0){
						printf("ERROR: socket() udp\n");
						exit(-1);
					}
					server.sin_family = AF_INET;
					server.sin_port = htons(atoi(argv[1])+1);
					server.sin_addr.s_addr = INADDR_ANY; 
					bzero(&(server.sin_zero),8); // escribimos ceros en el resto de la estructura
					
					fdbro = bind(fdbro,(struct sockaddr*)&server,sizeof(struct sockaddr));
					if (fdbro < 0) {
						printf("ERROR: bind() udp\n");
						exit(-1);
					}
					buf[0] = '\0';
					
					numbytes = recvfrom(fdbro, buf, MAX_LARGO_MENSAJE + 2, 0, (struct sockaddr *)&client, &sin_size);
					if (numbytes < 0){
						printf("ERROR: recvfrom() udp\n");
						exit(-1);
					}
					
					fecha[0] = '\0';
					fechaChar = fechayhora();
					strcpy(fecha, fechaChar);
					buf[numbytes-2]='\0';
					
					cout << "[" << fecha << "] " << buf << endl;
					
					close(fdbro);
				}

			}
	}

	if (pid>0){
		//Padre
		//Envia mensaje
	  padre = true;
	  
		printf("\33[34mTx\33[39m: Iniciada parte que transmite mensajes. Pid %d\n", getpid());
		
		while (true){
			
        	buf[0] = '\0';

			scanf(" %[^\n]", buf);
            ipreceptor[0] = '\0';
		   	long unsigned int i = 0;
			
			// Direccion destinario se obtiene del buffer
            while (buf[i]!=' '){
				ipreceptor[i]=buf[i];
				i++;
			}
			
			ipreceptor[i] = '\0';
			
			mensaje[0] = '\0';
            long unsigned int j = 0;
			i++;
			
			//Mensaje a enviar se obtiene del buffer
			while (i<strlen(buf)){
				mensaje[j]=buf[i];
				i++;
				j++;
			}
			mensaje[j]='\0';
			
			// Se no hay un * al principio del mensaje, manda por tcp
			if (ipreceptor[0]!='*'){
				
				buf[0] = '\0';
				strcpy(buf, usuario);
				strcat(buf," dice: ");
				strcat(buf, mensaje);
				strcat(buf, "\0");
				
				server.sin_family = AF_INET;
                server.sin_port = htons(atoi(argv[1]));
				server.sin_addr.s_addr = inet_addr(ipreceptor); // Dirección del destinatario del mensaje
				bzero(&(server.sin_zero),8);
				
				// crea socket tcp
				fd = socket(AF_INET, SOCK_STREAM, 0);
				if (fd < 0){
					printf("ERROR: socket() tcp\n");
					exit(-1);
				}
				
				numbytes = connect(fd,(struct sockaddr *)&server,sizeof(struct sockaddr));
				if (numbytes < 0){
					printf("ERROR: connect() envío\n");
					exit(-1);
				}
				
				numbytes = send(fd, buf, strlen(buf) + 2, 0);
				if (numbytes < 0){
					printf("ERROR: send() envio\n");
					exit(-1);
				}

				close(fd);
			} else { //Es broadcast
			
				int broadcast = 1;
				
				server.sin_family = AF_INET;
				server.sin_port = htons(atoi(argv[1])+2);
				server.sin_addr.s_addr = INADDR_ANY;
				bzero(&(server.sin_zero),8);
				
				
				buf[0] = '\0';
				//Guarda la ip en un archivo
				system("ifconfig | grep inet > ip.dat");
				//Lee la ip guardada
				if ((pf=fopen("ip.dat","r"))==NULL){
					printf("Error al abrir archivo ip.dat");
					exit(-1);
				}
        
				fscanf(pf,"%s",buf);
				buf[0] = '\0';
				fscanf(pf,"%s",buf);
				
				i=0;
				while (buf[i]!='1')
					i++;
				j=0;
				long unsigned int k = 0;
				k=i;
				
				while (j < strlen(buf)-k){
					buf[j]=buf[i];
					j++;
					i++;
				}
				buf[j] = '\0';
				fclose(pf);
				system("rm ip.dat");
				
				
				strcat(buf," ");
				strcat(buf,usuario); // agrega el usuario al mensaje
				strcat(buf," dice: ");
				strcat(buf, mensaje);
				strcat(buf, "\0");
				
				numbytes = socket(AF_INET, SOCK_DGRAM, 0);
				if (numbytes < 0){
					printf("ERROR: socket() udp broadcast\n");
					exit(-1);
				}
				
				numbytes = bind(fdbro,(struct sockaddr*)&server,sizeof(struct sockaddr));
				if (numbytes < 0) {
					printf("ERROR: bind() udp broadcast\n");
					exit(-1);
				}
				
				if (setsockopt(fdbro, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof broadcast) == -1) {
					printf("ERROR: setsockopt()\n");
					exit(-1);
				}

				server.sin_family = AF_INET;
				server.sin_port = htons(atoi(argv[1])+1);
				server.sin_addr.s_addr = htonl(-1);	// el valor -1 equivale a la dirección de broadcast
				bzero(&(server.sin_zero),8);
				
				numbytes = sendto(fdbro, buf, strlen(buf) + 2, 0, (struct sockaddr*)&server, sizeof server);
				if (numbytes < 0){
					printf("sendto() error\n");
					exit(-1);
				}

				close(fdbro);
			}
		}
	}
}


