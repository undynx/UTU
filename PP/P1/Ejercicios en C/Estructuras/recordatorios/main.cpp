#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct HoraExacta{
    int hora;
    int minuto;
    int segundo;
};

struct Recordatorio{
    char texto[30];
    HoraExacta reminder;
};

// DECLARACION DE FUNCIONES //

///Lee lo ingresado en consola hasta el tamaño deseado, luego sigue leyendo para limpiar el buffer;
void leer_linea(char arr[],int tam);

//////////////////////////////

///Crea una nueva hora para un recordatorio
HoraExacta nueva_hora();

//////////////////////////////

///Devuelve un recordatorio
Recordatorio crear_recordatorio();

//////////////////////////////

///Recibe una hora actual y una hora final y devuelve cuantas horas faltan
int cuanto_falta(HoraExacta hIni, HoraExacta hFinal);

//////////////////////////////

///Se ingresa una hora y muestra los recordatorios siguientes
void chequear_agenda(Recordatorio agenda[], int tam);

//////////////////////////////


int main()
{
    Recordatorio agenda[10]; //crea un array de 10 recordatorios
    int option, guardados=0;
    do{
        printf("MENU:\n1. Agregar recordatorio \n2. Ver agenda \n3. Salir");
        printf("\nQue deseas hacer?: ");
        scanf("%d", &option);
        getchar();
        switch (option){
            case 1:
                if(guardados < 10){
                    agenda[guardados]=crear_recordatorio();
                    guardados++;
                }else
                    printf("No puedes guardar mas de 10 recordatorios");
            break;
            case 2:
                chequear_agenda(agenda, guardados);
            break;
            case 3:

            break;
        }
    }while(option != 3);

    return 0;
}

// DEFINICION DE FUNCIONES //

///Lee lo ingresado en consola hasta el tamaño deseado, luego sigue leyendo para limpiar el buffer;
void leer_linea(char arr[],int tam){
    int pos=-1;
    do{
        if(pos<tam-1)
            pos++;
        arr[pos]=getchar();
    }while(arr[pos]!='\n');
    arr[pos]='\0';
}

//////////////////////////////

///Crea una nueva hora para un recordatorio
HoraExacta nueva_hora(){

    HoraExacta retorno;

    printf("Hora: ");
    scanf("%d", &retorno.hora);
    printf("Minutos: ");
    scanf("%d", &retorno.minuto);
    printf("Segundos: ");
    scanf("%d", &retorno.segundo);
    getchar();

    return retorno;
}

//////////////////////////////

///Devuelve un recordatorio
Recordatorio crear_recordatorio(){
    Recordatorio retorno;
    retorno.reminder = nueva_hora();

    printf("Que deseas que te recordemos?: ");
    leer_linea(retorno.texto, 30);
    return retorno;
}

//////////////////////////////

///Recibe una hora actual y una hora final y devuelve cuantas horas faltan
int cuanto_falta(HoraExacta hIni, HoraExacta hFinal){

    int cantHoras=-1;

    if(hIni.hora<=hFinal.hora){

        cantHoras = hFinal.hora - hIni.hora;

        if(hIni.minuto<hFinal.minuto){
            cantHoras++;
        }else{

            if(hIni.minuto == hFinal.minuto){
                if(hIni.segundo < hFinal.segundo)
                    cantHoras++;
                else if(cantHoras==0 && hIni.segundo>hFinal.segundo)
                    cantHoras = -1;
            } else if(cantHoras == 0)
                cantHoras = -1;
        }

    }

    return cantHoras;
}

//////////////////////////////

///Se ingresa una hora y muestra los recordatorios siguientes
void chequear_agenda(Recordatorio agenda[], int tam){

    int cantH;
    HoraExacta horaActual;
    horaActual = nueva_hora();
    printf("RECORDATORIOS:\n");

    for(int i=0 ; i<tam ; i++){
        cantH = cuanto_falta(horaActual, agenda[i].reminder);
        if(cantH>0){
            printf("\nEn %d horas\n", cantH);
            printf("Recordatorio: %s\n", agenda[i].texto);
            printf("---\n");
        }
    }
}
