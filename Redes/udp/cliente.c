// Redes de Computadoras
// Tecnologo en Informatica FIng - CETP
//
// Taller 3  - Programacion con Sockets UDP
// Cliente Hora

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
#include <netdb.h> // estructuras
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h> 
#include <sys/wait.h>
#include <sys/signal.h>
#include <ctype.h> 

#define MAX_LARGO_MENSAJE 255

using namespace std;
	
	int fd1;

void manejadorSenhales (int signal)
// Manejador de las senhales.
// Aca se debe implementar la accion a realizar cuando se recibe la senhal
// Deberia haber un manejador de senhales para cada hijo si hacen cosas distintas
{
	if (signal == SIGINT)
	{
		cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGINT CTRL+C recibido\33[00m\n";
	}
	if (signal == SIGTERM)
	{
		cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGTERM Terminacion de programa\33[00m\n";
	}
	if (signal == SIGSEGV)
	{
		cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGSEGV violacion de segmento\33[00m\n";
	}
	if (signal == SIGCHLD)
	{
		cout << "\33[46m\33[31m[" << "]" << " SIGCHLD \33[00m\n";
	}
	if (signal == SIGPIPE)
	{
		cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGPIPE \33[00m\n";
	}
	if (signal == SIGKILL)
	{
		cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGKILL \33[00m\n";
	}
	if (signal == SIGSEGV)
	{
		cout << "\33[46m\33[31m[" << getpid() << "]" << " SIGSEGV violacion de segmento\33[00m\n";
	}
	close(fd1);
	exit(1);
}

int main(int argc, char * argv[])
// En argc viene la cantidad de argumentos que se pasan,
// si se llama solo al programa, el nombre es el argumento 0
// En nuestro caso:
//      - argv[0] es el string "cliente", puede cambiar si se llama con otro path.
//      - argv[1] es el ip/dominio para conectarse.
//      - argv[2] es el puerto para conectarse.
//      - argv[3] comando a ejecutar [fecha|hora]

{

	if (argc < 4)
	{
			cout << "\33[46m\33[31m[ERROR]:" << " Faltan argumentos: ip, port, comando\33[00m\n";
			exit (0);
	}

	if ((strcmp(argv[3], "hora") != 0) && (strcmp(argv[3], "fecha") != 0)){
		printf("ERROR: comando %s incorrecto\n", argv[3]);
    exit(-1);
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

	cout << "\33[34mRedes de Computadoras\33[39m: Cliente UDP Fecha/Hora.\nProceso de pid: " << getpid() << ".\n";


	// --------------------- 
	//Crea estructuras para guardar la informacion de los servidores
	
	// para la informacion de la direccion del servidor
	struct sockaddr_in server; 
	// para la informacion de la direccion del cliente 
	struct sockaddr_in client;


	// --------------------- 
	//Crea un buffer para el largo del mensaje
	char buf[MAX_LARGO_MENSAJE]; 
	int numbytes;


	// --------------------- 
	// Resuelve DNS

	struct hostent *he; //estructura que recibira la informacion del nodo remoto

	if((he=gethostbyname(argv[1])) == NULL){
		printf("gethostbyname() error \n");
		exit(-1);
	}


	// --------------------- 
	//Creacion del socket UDP (SOCK_DGRAM)
	
	fd1 = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	
	if ( fd1 < 0 ) {  //Verifica que se haya creado correctamente
		printf("error en socket()\n");
		exit(-1);
	}
 

	// --------------------- 
	//Completa la informacion de la direccion del Cliente
	
	server.sin_family = AF_INET; //Guarda el tipo de socket
	
	server.sin_port = htons(atoi(argv[2])); //Guarda el numero de puerto de recepcion
	//atoi convierte un char a entero
	//htons convierte el valor argv que es recibido por parametro en un num de puerto
	
	server.sin_addr = *((struct in_addr *)he->h_addr); //ip o dominio a conectarse
	/*he->h_addr pasa la información de ``*he'' a "h_addr" */
	
	bzero(&(server.sin_zero),8); // escribimos ceros en el reto de la estructura


	// --------------------- 
	//Bind
	
	/*int errorBind = bind(fd1, (struct sockaddr*)&server, sizeof(struct sockaddr));
	
	if(errorBind < 0) { //Verifica que se haya bindeado correctamente
      printf("error en bind() \n");
      exit(-1);
	}*/


	// ---------------------
	//Send to
	//Guarda en el buffer lo que va a enviar y lo envia

	unsigned int size = sizeof(struct sockaddr);

	if(strcmp(argv[3], "hora") == 0){
		sendto(fd1, "hora\r\n", 6, 0, (struct sockaddr*)&server, size);
	} else{
		sendto(fd1, "fecha\r\n", 7, 0, (struct sockaddr*)&server, size);
	}

	

	// ---------------------
	//Receive from

	numbytes = recvfrom(fd1, buf, MAX_LARGO_MENSAJE, 0, (struct sockaddr*)&client, &size);
	buf[numbytes -2] = '\0';

	cout << buf << endl;

	close(fd1);

}


