
// Redes de Computadoras - Curso 1er Semestre 2016
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
#include<errno.h> //For errno - the error number
#include<netdb.h> //hostent


using namespace std;

int fd, fd2, fdnew; // los ficheros descriptores
FILE * redes_file;          // puntero a archivo

int hostname_to_ip(char * hostname , char* ip)
{
    struct hostent *he;
    struct in_addr **addr_list;
    int i;

    if ( (he = gethostbyname( hostname ) ) == NULL)
    {
        // get the host info
        herror("gethostbyname");
        return 1;
    }

    addr_list = (struct in_addr **) he->h_addr_list;

    for(i = 0; addr_list[i] != NULL; i++)
    {
        //Return the first one;
        strcpy(ip , inet_ntoa(*addr_list[i]) );
        return 0;
    }

    return 1;
}

void fechayhora(char * feyho){
// Procedimiento para obtener la fecha y hora actual y devolverla en el formato solicitado (AAAA-MM-DD HH:MM)
     time_t tiempo = time(0);
     struct tm *tlocal = localtime(&tiempo);
     strftime(feyho,18,"%Y.%m.%d %H:%M",tlocal);
}

void fecha_y_hora(char * fyo){
// Procedimiento para obtener la fecha y hora actual y devolverla en el formato solicitado (AAAA-MM-DD HH:MM)
     time_t tiempo = time(0);
     struct tm *tlocal = localtime(&tiempo);
     strftime(fyo,18,"%Y.%m.%d %H:%M",tlocal);
}

///**************************** ES IP O HOSTNAME ************************///

///Funcion para determinar si es un host o una ip, devuelve true en caso de ser ip y false en caso de ser host
bool esIP(char dest[]){


int i=0;
bool ip=false;



for(i=0; i < strlen(dest); i++){

    if(dest[i]!='.' && dest[i] !='1' && dest[i]!='2' && dest[i]!='3' && dest[i]!='4' && dest[i]!='5' && dest[i]!='6' && dest[i]!='7' && dest[i]!='8' && dest[i]!='9'){

        ip = false;
        i++;

        }

    else{

        ip = true;

        }

    }//fin iteracion


return ip;

}

///**************************** EXTRAER MENSAJE ************************///

void extraerMensaje(char bufferfer[],char mensaje[MAX_LARGO_MENSAJE]){

    int i=0;
    int j=0;

    while(bufferfer[i] != ' ') i++;
    i++;
    //i+=2;

    for(j=0; j<= i - strlen(bufferfer); j++){

        mensaje[j] = bufferfer[i];
        i++;

        }

      mensaje[j] = '\0'; //agregamos null al final

}

///**************************** EXTRAER DESTINATARIO ************************///

///Funcion para extraer destinatario, ya sea hostname o ip, devuelve un string
void extraerDestinatario(char bufferfer[], char * dest){

 int i = 0;


    while(bufferfer[i] != ' ')

    {

    dest[i] = bufferfer[i];

    i++;


    }

dest[i] = '\0';

}



///**************************** MAIN ************************///



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
			exit(1);
	}




	//cout << "\33[34mRedes de Computadoras 2014\33[39m: Sistema de Mensajeria.\nEscuchando en el puerto " << argv[1] << ".\nProceso de pid: " << getpid() << ".\n";

	// ***********************************
	// Definición de valiables locales al main

	struct sockaddr_in server, client;	// estructuras para la información de las direcciones del servidor y el cliente
	char buffer[MAX_LARGO_MENSAJE]; 		// bufferfer para guardar datos enviados o recibidos por las conexiones
	int broadcast; 						// variable para setear el setsockopt y permitir envío de broadcast
	int pid, pid2;						// identificadores de procesos
	int i, j, k; 							// variables para moverse por el bufferfer para leerlo
	char ipreceptor[30];				// arreglo para guardar ip del destinatario leída de la entrada
	char usuario[MAX_USR_PWD];			// arreglo para guardar el usuario leido de la entrada
	char clave[MAX_USR_PWD];			// arreglo para guardar la password del usuario leida de la entrada
	char mensaje[MAX_LARGO_MENSAJE];	// arreglo para guardar el mensaje a enviar leído de la entrada
	int numbytes;						// numero de bytes recibidos en la conexión
	char cmd5[33];						// arreglo para guardar clave codificada en md5
    char com[100];						// arreglo para guardar el comando que ejecurará el sistema para crear la clave md5
    char fecha[18];						// arreglo para guardar la fecha y hora
    char destinatario[MAX_LARGO_MENSAJE];//se guarda el destinatario, puede ser hostname o ip, luego convertimos el hostname a ip con la funcion hostname_to_ip

	// ***********************************
	// Inicio de Autenticación del usuario al Servidor de Autenticación

	// A continuación la llamada a socket() para crear socket tcp
	if ((fd=socket(AF_INET, SOCK_STREAM, 0))==-1){
	    printf("ERROR: Imposible abrir socket al Servidor de Autenticacion en %s:%s\n", argv[2], argv[3]);
	    exit(1);
	}
	// inicializamos la estructura server
	server.sin_family = AF_INET;					// familia de la dirección
    server.sin_port = htons(atoi(argv[3]));			// convietimos primero a entero y luego a variable corta de red el puerto donde escucha el servidor de autenticación pasado como parámetro
    server.sin_addr.s_addr = inet_addr(argv[2]);	// convertimos a entero largo sin signo la dirección del servidor de autenticación  pasada como parámetro
    bzero(&(server.sin_zero),8); 					// escribimos ceros en el resto de la estructura
	// A continuación la llamada a bind() para vincular estructura server al file descriptor fd
    if (connect(fd, (struct sockaddr *)&server, sizeof(struct sockaddr))==-1){
		printf("ERROR: Imposible conectar con Servidor de Autenticacion en %s:%s\n", argv[2], argv[3]);
		exit(1);
    }
    numbytes=0; 									// inicializamos a 0 el numero de bytes recibidos
	buffer[0] = '\0';									// inicializamos a NULL el arreglo para asegurarnos que esté vacío
	// A continuación la llamada a recv() para recibir mensaje de bienvenida desde el servidor de autenticación
    if ((numbytes = recv(fd, buffer, MAX_LARGO_MENSAJE, 0)) == -1){
		printf("ERROR: Imposible recibir datos del Servidor de Autenticacion en %s:%s\n", argv[2], argv[3]);
		exit(1);
    }
    // Ahora pedimos y leemos usuario y password de la entrada
    cout << "Usuario: ";
    cin >> usuario;
    cout << "Clave: ";
    cin >> clave;
  	com[0] = '\0';									// inicializamos a NULL el arreglo para asegurarnos que esté vacío
	// Ahora armamos el comando a ser ejecutado por el sistema para generar la clave md5 en el archivo md5.dat
	strcpy(com,"echo ");
    strcat(com,clave);
    strcat(com," | md5sum > md5.dat");
	// A continuación ejecutamos el comando para generar la clave md5
    system(com);
	// Abrimos el archivo md5.dat en modo lectura
    if ((redes_file=fopen("md5.dat","r"))==NULL){
        printf("ERROR: Imposible codificar clave\n");
        exit(1);
    }
	cmd5[0] = '\0';									// inicializamos a NULL el arreglo para asegurarnos que esté vacío
	// Leemos la primera linea del archivo hasta el espacio y lo guardamos en el arreglo cmd5
    fscanf(redes_file,"%s",cmd5);
	// Cerramos el archivo
    fclose(redes_file);
    strcat(cmd5,"\0");
    // Eliminamos el archivo auxiliar que creamos
    system("rm md5.dat");
	buffer[0] = '\0';
	// Ahora armamos el bufferfer con usuario-clave_en_md5 para enviar al servidor de autenticación
	strcpy(buffer,usuario);
    strcat(buffer,"-");
    strcat(buffer,cmd5);
    strcat(buffer,"\0");
    // A continuación enviamos el bufferfer generado en el paso anterior
	if (send(fd, buffer, strlen(buffer) + 2, 0)==-1){
        cout << "ERROR: Imposible enviar datos al servidor de Autenticacion\n";
        exit(1);
    }
    numbytes=0;
    buffer[0] = '\0';
	// Ahora recibimos respuesta del servidor de autenticacion (SI o NO dependiendo del chequeo de los datos que enviamos)
    if ((numbytes = recv(fd, buffer, MAX_LARGO_MENSAJE, 0)) == -1){
       cout << "ERROR: Imposible recibir datos del servidor de Autenticacion\n";
       exit(1);
	}
	// Agregamos NULL al final de lo que recibimos descartando el \r\n del final
	buffer[numbytes-2]='\0';
	// Si usuario y/o password están mal avisamos y salimos del programa
	if (strcmp(buffer,"NO") == 0){
	    cout << "ERROR: Imposible autenticar con el usuario y password ingresados\n";
	    exit(1);
	}
    // Recibimos nombre del usuario desde el servidor de autenticacion
    numbytes=0;
    buffer[0] = '\0';
    if ((numbytes=recv(fd, buffer, MAX_LARGO_MENSAJE, 0)) == -1){
       cout << "ERROR: Imposible recibir nombre de usuario del servidor de Autenticacion\n";
       exit(1);
	}
	buffer[numbytes-2]='\0';
	// Como no necesitamos más datos del servidor de autenticación cerramos el socket
	close(fd);
	// Damos mensaje de bienvenida al chat al nombre de usuario obtenido
	cout << "Bienvenido " << buffer << endl;

	// termino conexion con servidor de autenticacion
	// **************************************************************
    unsigned int sin_size;
	// Hacemos primera bifurcación para atender recepción y transmisión
    pid = fork();
    if (pid < 0)
	{
		printf("ERROR: error en fork() \n");
		exit(1);
   	}


    if (pid == 0)   // servidor recibe mensaje
	{


	// Creamos el archivo mensajeria.log en modo escritura
    if ((redes_file=fopen("mensajeria.log","w"))==NULL){
         printf("Error al crear archivo mensajeria.log");
         exit(1);
    }
    fecha[0] = '\0';
	// Obtenemos la fecha y hora actual en el arreglo fecha
    fechayhora(fecha);
    // Guardamos en el archivo mensajeria.log los datos que pide en la letra
    fprintf(redes_file,"<<<%s - puerto %s con pids = %i y %i>>>\n",fecha,argv[1],getpid(),getppid());
    fprintf(redes_file,"%s->Autenticado->%s\n",fecha,usuario);
	// Cerramos el archivo mensajeria.log
    fclose(redes_file);
	    //printf("\33[34mRx\33[39m: Iniciada parte que recepciona mensajes. Pid %d\n", getpid());
	// Hacemos segunda bifurcación para recibir tanto paquetes tcp como udp
		pid2 = fork();
		if (pid2<0)
		{
			printf("ERROR: error en fork() \n");
			exit(1);
        }
		if (pid2 == 0)   // servidor recibe tcp
        {

            if ((fd=socket(AF_INET, SOCK_STREAM, 0)) == -1 ){
				printf("ERROR: Imposible abrir socket tcp para recepción\n");
				exit(1);
				}

			server.sin_family = AF_INET;
			server.sin_addr.s_addr = INADDR_ANY;		// INADDR_ANY coloca nuestra dirección IP automáticamente
			server.sin_port = htons(atoi(argv[1]));
			bzero(&(server.sin_zero),8);
			// A continuación la llamada a socket() para crear socket tcp


			if (bind(fd,(struct sockaddr*)&server,sizeof(struct sockaddr))==-1) {
				printf("ERROR: Imposible hacer bind() para recepcion\n");
				exit(1);
			}
			// Habilitamos al servidor a escuchar hasta BACKLOG conexiones
			if (listen(fd,BACKLOG) == -1){
				printf("ERROR: Imposible hacer listen() para recepcion\n");
				exit(1);
			}

			// A continuación hacemos while para permanecer recibiendo mensajes
			while (true){

                sin_size=sizeof(struct sockaddr_in);
				// A continuación la llamada a accept() en un nuevo file descriptor fd2 asociado al fd
				if ((fd2 = accept(fd,(struct sockaddr *)&client, &sin_size)) == -1){
					printf("ERROR: Imposible hacer accept() para recepcion\n");
					exit(1);
				}
				buffer[0] = '\0';
				numbytes = 0;
				// Ahora recibimos mensaje
				if ((numbytes=recv(fd2, buffer, MAX_LARGO_MENSAJE, 0)) == -1){
                    printf("ERROR: Imposible hacer recv() para recepcion\n");
                   	exit(1);
				}
				fecha[0] = '\0';
				fechayhora(fecha);
				buffer[numbytes-2]='\0';
				// Ahora imprimimos en pantalla del receptor la linea de salida especificada en la letra
				cout << "[" << fecha << "] " << inet_ntoa(client.sin_addr) << " " << buffer << endl;
				// Abrimos el archivo mensajeria.log en modo de escritura para actualizarlo con lo recibido


				if ((redes_file=fopen("mensajeria.log","a+"))==NULL){
					printf("Error al abrir archivo mensajeria.log para actualizar");
					exit(1);
				}

				// Actualizamos el archivo mensajeria.log
				fprintf(redes_file,"[%s] %s %s\n",fecha,inet_ntoa(client.sin_addr),buffer);
				// Cerramos el archivo mensajeria.log
				fclose(redes_file);
				// Cerramos conexión abierta con el accept()
				close(fd2);
			}
			// Cerramos el socket
			close(fd);
		}
		if (pid2 > 0)   // servidor recibe udp
        {
			server.sin_family = AF_INET;
			server.sin_addr.s_addr = INADDR_ANY;
			server.sin_port = htons(atoi(argv[1]+1));
			bzero(&(server.sin_zero),8);
			sin_size = sizeof(struct sockaddr_in);
			while (true){
				// A continuación la llamada a socket() para crear socket udp
				if ((fdnew=socket(AF_INET, SOCK_DGRAM, 0)) == -1 ){
					printf("ERROR: Imposible crear socket udp\n");
					exit(1);
				}
				server.sin_family = AF_INET;
				server.sin_addr.s_addr = INADDR_ANY;   // INADDR_ANY coloca nuestra dirección IP automáticamente
				server.sin_port = htons(atoi(argv[1])+1);
				bzero(&(server.sin_zero),8); // escribimos ceros en el resto de la estructura

				// A continuación la llamada a bind() para vincular socket udp
				if (bind(fdnew,(struct sockaddr*)&server,sizeof(struct sockaddr))==-1) {
					printf("ERROR: Imposible hacer bind() para recepción\n");
					exit(1);
				}
				buffer[0] = '\0';
				// Ahora recibimos mensaje
				if ((numbytes = recvfrom(fdnew, buffer, MAX_LARGO_MENSAJE + 2, 0, (struct sockaddr *)&client, &sin_size)) == -1){
					printf("ERROR: Imposible hacer recvfrom() para recepcion\n");
					exit(1);
				}
				fecha[0] = '\0';
				fechayhora(fecha);
				buffer[numbytes-2]='\0';
				// Ahora imprimimos en pantalla del receptor la linea de salida especificada en la letra
				cout << "[" << fecha << "] " << buffer << endl;
				// Abrimos el archivo mensajeria.log en modo de escritura para actualizarlo con lo recibido
				if ((redes_file=fopen("mensajeria.log","a+"))==NULL){
					printf("Error al abrir archivo mensajeria.log para actualizar");
					exit(1);
				}
				// Actualizamos el archivo mensajeria.log
				fprintf(redes_file,"[%s] %s\n",fecha,buffer);
				// Cerramos el archivo mensajeria.log
				fclose(redes_file);
				// Cerramos el socket
				close(fdnew);
			}

		}
	}

	if (pid>0)   // cliente envia mensaje
	{

    //    printf("\33[34mTx\33[39m: Iniciada parte que transmite mensajes. Pid %d\n", getpid());
		// A continuación hacemos while para permanecer recibiendo mensajes
		while (true)
        {
        	buffer[0] = '\0';
			// Leemos datos de la entrada y los guardamos en el buffer
			scanf(" %[^\n]", buffer);

            destinatario[0] = '\0';
		   	extraerDestinatario(buffer,destinatario);

			mensaje[0] = '\0';
            extraerMensaje(buffer,mensaje);


			// Detectamos si hay que enviar por tcp o broadcast udp
			if (destinatario[0]!='*'){
			// Acá enviamos por tcp
				// Armamos mensaje a enviar
				buffer[0] = '\0';
				strcpy(buffer,usuario);
				strcat(buffer," Dice: ");
				strcat(buffer,mensaje);
				strcat(buffer,"\0");

                //controlamos si el usuario ingresa una ip o un host, luego convertimos el hostname en ip
                if(!esIP(destinatario)){
                hostname_to_ip(destinatario,ipreceptor);
                }
                else extraerDestinatario(buffer,ipreceptor);


				server.sin_family = AF_INET;
                server.sin_port = htons(atoi(argv[1]));
				server.sin_addr.s_addr = inet_addr(ipreceptor); 	// Dirección del destinatario del mensaje
				bzero(&(server.sin_zero),8);

				// A continuación la llamada a socket() para crear socket tcp
				if ((fd=socket(AF_INET, SOCK_STREAM, 0))==-1){
					printf("ERROR: Imposible crear socket tcp\n");
					exit(1);
				}
				// A continuación la llamada a connect() para establecer conexión
				if (connect(fd,(struct sockaddr *)&server,sizeof(struct sockaddr))==-1){
					printf("ERROR: Imposible hacer connect() para envío\n");
					exit(1);
				}
				if ((redes_file=fopen("mensajeria.log","a+"))==NULL){
       				printf("Error al abrir archivo mensajeria.log para actualizar");
       				exit(1);
				}
				// Actualizamos el archivo mensajeria.log
				fprintf(redes_file,"%s %s\n",inet_ntoa(server.sin_addr),mensaje);
				// Cerramos el archivo mensajeria.log
				fclose(redes_file);
				// A continuación la llamada a send() para enviar mensaje
				if (send(fd, buffer, strlen(buffer) + 2, 0)==-1){
					printf("ERROR: Imposible hacer send() para envío\n");
					exit(1);
				}
				// Abrimos el archivo mensajeria.log en modo de escritura para actualizarlo con lo enviado

				// Cerramos el socket
				close(fd);



			}

// Acá enviamos broadcast por udp----------------------------------



else {
broadcast = 1;
server.sin_family = AF_INET;
server.sin_port = htons(atoi(argv[1])+2);
server.sin_addr.s_addr = INADDR_ANY;
bzero(&(server.sin_zero),8);


// Armamos mensaje a enviar
buffer[0] = '\0';

// Seguimos armando el mensaje a enviar
strcat(buffer," ");
strcat(buffer,usuario);
strcat(buffer," dice: ");
strcat(buffer,mensaje);
strcat(buffer,"\0");
// A continuación la llamada a socket() para crear socket udp
if ((fdnew=socket(AF_INET, SOCK_DGRAM, 0))==-1){
printf("ERROR: Imposible crear socket udp\n");
exit(1);
}
// A continuación la llamada a bind() para vincular socket udp
if (bind(fdnew,(struct sockaddr*)&server,sizeof(struct sockaddr))==-1) {
printf("ERROR: Imposible hacer bind() para envío\n");
exit(1);
}
// Ahora llamamos a setsockopt que es la función que permite que sean enviados paquetes de broadcast
if (setsockopt(fdnew, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof broadcast) == -1) {
printf("ERROR: Imposible hacer setsockopt() para envío\n");
exit(1);
}

server.sin_family = AF_INET;
server.sin_port = htons(atoi(argv[1])+1);
server.sin_addr.s_addr = htonl(-1);					// el valor -1 equivale a la dirección de broadcast
bzero(&(server.sin_zero),8);

if ((redes_file=fopen("mensajeria.log","a+"))==NULL){
printf("Error al abrir archivo mensajeria.log para actualizar");
exit(1);
}
// Actualizamos el archivo mensajeria.log
fprintf(redes_file,"* %s\n",mensaje);
// Cerramos el archivo mensajeria.log
fclose(redes_file);
// A continuación la llamada a sendto() para enviar mensaje
if (sendto(fdnew, buffer, strlen(buffer) + 2, 0, (struct sockaddr*)&server, sizeof server)==-1){
printf("sendto() error\n");
exit(1);
}
// Abrimos el archivo mensajeria.log en modo de escritura para actualizarlo con lo enviado

// Cerramos el socket
close(fdnew);
			}
		}
	}
}































