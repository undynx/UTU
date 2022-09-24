#include <iostream>

using namespace std;

///Esta funcion retorna la cantidad de divisores de un numero
int cantDivisores(int numUser){
    int cant = 0;
    for(int i=1 ; i<=numUser ; i++){
        if(numUser%i==0){
            cant++;
        }
    }
    return cant;
}

///Esta funcion retorna si un numero es primo o no
bool es_Primo(int numUser){
    int cant;
    bool confirm;
    cant = cantDivisores(numUser);
    if(cant == 2)
        confirm = true;
    else
        confirm = false;

    return confirm;
}

int main()
{
    int intentos=0, numUser, cant, cantNoPrimos=0;

    printf("Ingresa cantidad de primos que desees buscar: ");
    scanf("%d", &intentos);

    while(intentos>0){
        printf("Te faltan %d primos", intentos);
        printf("\nIngresa un numero: ");
        scanf("%d", &numUser);

        if(es_Primo(numUser)){
            intentos--;
        } else{
            cantNoPrimos++;
        }
    }

    printf("\nIngresaste %d no primos", cantNoPrimos);

    return 0;
}
