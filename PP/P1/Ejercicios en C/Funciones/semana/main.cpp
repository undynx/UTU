#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;

// Variables Globales //
const int tam = 10;

//////////////////////////////////////

//Declaración de funciones//
///Inicializa el array semana rellenandolo con "Vacio"
void iniciar_semana(char semana[][tam]);

///Imprime la semana a partir de un día que se pasa como parámetro
void imprimir_semana(char semana[][tam], int dia);

///Lee una línea como un string, y limpia el buffer
void leer_linea(char arr[], int tam);

///Cambia el texto guardado en este dia
void cambiar_dia(char dia[]);

//////////////////////////////////////

int main()
{
    char semana[7][tam];
    int dia, opcion, cambio;

    printf("Elegi el dia en el que inicia la semana: 0-lunes, 1-martes, etc: ");
    scanf("%d", &dia);
    iniciar_semana(semana);

    do{
        printf("Que deseas hacer?\n1. Salir \n2. Cambiar texto de un dia \n3. Ver semana\n4. Reestablecer\n");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                printf("Saliendo...");
            break;
            case 2:
                printf("Indica el dia que deseas cambiar: ");
                scanf("%d", &cambio);
                getchar();
                cambiar_dia(semana[cambio]);
            break;
            case 3:
                imprimir_semana(semana, dia);
            break;
            case 4:
                iniciar_semana(semana);
            break;
            default:
                printf("Ese numero no es valido");
            break;
        }

    }while(opcion != 1);


    return 0;
}

///Inicializa el array semana rellenandolo con "Vacio"
void iniciar_semana(char semana[][tam]){

    for(int i=0 ; i<7 ; i++){
        strcpy(semana[i], "Vacio");
    }

}

///Imprime la semana a partir de un día que se pasa como parámetro
void imprimir_semana(char semana[][tam], int dia){

    for(int i=0; i<7 ; i++){
        //se hace el mod 7 por si el usuario ingresa por ej 4
        //igual se imprima bien el dia
        switch ((dia+i)%7){
            case 0: printf("Lunes"); break;
            case 1: printf("Martes"); break;
            case 2: printf("Miercoles"); break;
            case 3: printf("Jueves"); break;
            case 4: printf("Viernes"); break;
            case 5: printf("Sabado"); break;
            case 6: printf("Domingo"); break;
        }

        printf("%9s |", semana[i]);
    }
    printf("\n");

}

///Lee una línea como un string, y limpia el buffer
void leer_linea(char arr[], int tam){
    int pos=-1;
    do{
        if(pos<tam-1)
            pos++;
        arr[pos]=getchar();
    }while(arr[pos]!='\n');
    arr[pos]='\0';
}

///Cambia el texto guardado en este dia
void cambiar_dia(char dia[]){
    printf("Ingresa el texto que desees cambiar: ");
    leer_linea(dia, tam);
}
