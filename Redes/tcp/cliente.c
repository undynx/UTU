// Redes de Computadoras
// Tecnologo en Informatica FIng - CETP
//
// Taller 3  - Programacion con Sockets TCP
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
//      - argv[1] es el ip para conectarse.
//      - argv[2] es el puerto para conectarse.
//      - argv[3] comando a ejecutar [fecha|hora]

{

	if (argc < 4)
	{
			cout << "\33[46m\33[31m[ERROR]:" << " Faltan argumentos: ip, port, comando.\33[00m\n";
			exit (0);
	}

	if ((strcmp(argv[3], "hora") != 0) && (strcmp(argv[3], "fecha") != 0)){
		printf("ERROR: comando incorrecto\n");
      		exit(0);
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

	cout << "\33[34mRedes de Computadoras\33[39m: Cliente TCP Fecha/Hora.\nProceso de pid: " << getpid() << ".\n";


	// --------------------- 
	//Creación del socket TCP (SOCK_STREAM)
	
	fd1 = socket(AF_INET, SOCK_STREAM, 0);
	
	if ( fd1 < 0 ) {  //Verifica que se haya creado correctamente
		printf("error en socket()\n");
		exit(-1);
	}
	
	char buf[MAX_LARGO_MENSAJE];
	
	// Estructura que guardará la información sobre el nodo remoto
	struct hostent *he; //he == host entry
	//resuelve el DNS para conectarse
	he = gethostbyname(argv[1]);
	if(he == NULL){
		printf("gethostbyname() error\n");
		exit(-1);
	}
	
	// para la información de la dirección del servidor
	struct sockaddr_in server; 
	
	server.sin_family = AF_INET;
	server.sin_port = htons(atoi(argv[2])); //Puerto a conectarse
	server.sin_addr = *((struct in_addr *)he->h_addr); //ip o dominio a conectarse
	bzero(&(server.sin_zero),8); //Completa con ceros la estructura
	
	
	// --------------------- 
	// Conectar
	int error = connect(fd1, (struct sockaddr *)&server, sizeof(struct sockaddr));
	if(error < 0){
		printf("connect() error\n");
		exit(-1);
	}
	
	
	// --------------------- 
	// Receive
	int numbytes = recv(fd1, buf, MAX_LARGO_MENSAJE, 0);
	if(numbytes < 0){
		printf("Error en recv() \n");
		exit(-1);
	}
	
	buf[numbytes-2] = '\0'; //Agrega \0 para finalizar el string y poder compararlo
	
	//Verifica que sea el protocolo correcto con el mensaje
	if(strcmp(buf, "Redes - Servidor Hora") == 0){
		printf("ERROR: Protocolo incorrecto\n");
		exit(-1);
	}
	
	
	// --------------------- 
	// Send
	if(strcmp(argv[3], "hora") == 0){
		send(fd1, "hora\r\n", 6, 0);
	}else{
		send(fd1, "fecha\r\n", 7, 0);
	}
	
	
	// --------------------- 
	// Receive
	numbytes = recv(fd1, buf, MAX_LARGO_MENSAJE, 0);
	if(numbytes < 0){
		printf("Error en recv2() \n");
		exit(-1);
	}
	
	buf[numbytes-2] = '\0';
	
	cout << buf << endl;
	
	close(fd1);
}
