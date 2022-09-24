#include <iostream>
#include <stdio.h>
#include <stdlib.h>

const int tam = 5;
const int salario = 200;

/////////////////////////////

struct HoraExacta{
    int hora;
    int minuto;
    int segundo;
};

struct Empleado{
    char nombre[10];
    int cedula;
    HoraExacta horaEntrada;
};

//DECLARACION DE FUNCIONES//

///Lee lo ingresado en consola hasta el tamaño deseado, luego sigue leyendo para limpiar el buffer;
void leer_linea(char arr[],int tam);

///Crea una nueva hora exacta
HoraExacta nueva_hora();

///Recibe un arreglo de empleados y la cedula y devuelve true si ya existe uno con esa cedula
bool existe_empleado(Empleado emp[], int cantEmpleados, int cedula);

///Recibe un arreglo de empleados y crea uno nuevo con nombre y cedula (unica)
void crear_empleado(Empleado emp[], int &cantEmpleados, int tam);

///Recibe un arreglo de empleados y pide que se ingrese hora de entrada de cada uno
void ingresar_horas_todxs(Empleado emp[], int cantEmpleados);

///Recibe un arreglo y la cantidad de empleados y devuelve el salario de cada uno
void cerrar_dia(Empleado emp[], int cantEmpleados);

///////////////////////////

int main()
{
    Empleado empresa[tam];
    int opc, cantEmpleados=0;

    do{
        printf("MENU \n1. Crear nuevo empleado \n2. Cargar horas a todos los empleados \n3. Cerrar el día \n4. Salir \n");
        scanf("%d", &opc);

        switch (opc){
            case 1:
                if(cantEmpleados<tam){
                    crear_empleado(empresa, cantEmpleados, tam);
                } else {
                    printf("No hay mas vacantes");
                }
            break;
            case 2:
                ingresar_horas_todxs(empresa, cantEmpleados);
            break;
            case 3:
                cerrar_dia(empresa, cantEmpleados);
            break;
        }

    }while(opc != 4);

    return 0;
}

///////////////////////////

//DEFINICION DE FUNCIONES//

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


///Crea una nueva hora exacta
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


///Recibe un arreglo de empleados y la cedula y devuelve true si ya existe uno con esa cedula
bool existe_empleado(Empleado emp[], int cantEmpleados, int cedula){
    bool existeEmpleado = false;

        for (int i=0 ; i<cantEmpleados ; i++){
            if(emp[i].cedula == cedula){
                existeEmpleado = true;
                i=cantEmpleados;
            }
        }

    return existeEmpleado;
}


///Recibe un arreglo de empleados y crea uno nuevo con nombre y cedula (unica)
void crear_empleado(Empleado emp[], int &cantEmpleados, int tam){

    int cedula;

    printf("Ingresa la cedula: ");
    scanf("%d", &cedula);
    getchar();

    while(existe_empleado(emp, cantEmpleados, cedula)){
        printf("Esta cedula ya esta registrada, ingresa otra: ");
        scanf("%d", &cedula);
        getchar();
    }

    emp[cantEmpleados].cedula = cedula;
    printf("Ingresa el nombre: ");
    leer_linea(emp[cantEmpleados].nombre, 10);

    cantEmpleados++;
}


///Recibe un arreglo de empleados y pide que se ingrese hora de entrada de cada uno
void ingresar_horas_todxs(Empleado emp[], int cantEmpleados){

    for(int i=0 ; i<cantEmpleados ; i++){
        printf("Ingresa horario de entrada de %s \n", emp[i].nombre);
        emp[i].horaEntrada = nueva_hora();
    }

}


///Calcula la cantidad de horas que pasaron entre dos horas
int horas_que_pasaron(HoraExacta hIni, HoraExacta hFin){
    int result=-1;
    if(hIni.hora<=hFin.hora){
        result=hFin.hora-hIni.hora;
        if(hIni.minuto<hFin.minuto)
            result++;
        else{
            if(hIni.minuto==hFin.minuto)
                if(hIni.segundo<hFin.segundo)
                    result++;
                else if(result==0 and hIni.segundo>hFin.segundo)
                    result=-1;
            else if(result==0)
                result=-1;
        }
    }
    return result;
}


///Recibe un arreglo y la cantidad de empleados y devuelve el salario de cada uno
void cerrar_dia(Empleado emp[], int cantEmpleados){

    int horasTrabajadas;
    HoraExacta horaActual;

    printf("Ingresa la hora de finalizacion de la jornada\n");
    horaActual = nueva_hora();
    printf("A abonar:");

    for(int i=0 ; i<cantEmpleados ; i++){
        horasTrabajadas = horas_que_pasaron(emp[i].horaEntrada, horaActual);
        printf("\nEMPLEADO: %s", emp[i].nombre);
        printf("\nHORAS TRABAJADAS: %d", horasTrabajadas);
        printf("\nPAGO: %d\n", horasTrabajadas*salario);
    }

}
