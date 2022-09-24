#include <stdio.h>
#include <stdlib.h>

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
    if(cant != 2)
        confirm = false;
    else
        confirm = true;

    return confirm;
}

int main()
{

    int intentos, numUser = 0, cantNoPrimos = 0, cantPrimos = 0;

    printf("Ingresa cantidad de intentos: ");
    scanf("%d", &intentos);

    for(int i=0 ; i<intentos ; i++){
        printf("Ingresa un numero: ");
        scanf("%d", &numUser);
        if(es_Primo(numUser)){
            cantPrimos++;
        } else {
            cantNoPrimos++;
        }
    }

    printf("\nDe %d intentos, %d fueron no primos y %d fueron primos", intentos, cantNoPrimos, cantPrimos);

    return 0;
}
