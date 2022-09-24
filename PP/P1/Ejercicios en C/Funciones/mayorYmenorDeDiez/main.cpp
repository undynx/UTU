#include <iostream>

using namespace std;

///Esta funcion devuelve el mayor y menor de 10 numeros
int mayor_Y_Menor_10(int &mayorF, int &menorF){
    int numUser, rep = 1, cantPositivosF = 0;
    bool primera = true;

//    printf("Ingresa un numero: ");
//    scanf("%d", &numUser);
//    mayorF = numUser;
//    menorF = numUser;

    while(rep<=10){
        printf("Ingresa un numero: ");
        scanf("%d", &numUser);
        if(primera){
            mayorF = numUser;
            menorF = numUser;
            primera = false;
        }

        if(numUser > 0)
            cantPositivosF++;

        if(numUser > mayorF){
            mayorF = numUser;
        } else if(numUser < menorF){
            menorF = numUser;
        }

        rep++;
    }

    return cantPositivosF;
}

int main()
{
    int mayor = 0;
    int menor = 0;
    int cantPositivos;

    cantPositivos = mayor_Y_Menor_10(mayor, menor);
    printf("\nEl mayor fue %d y el menor %d", mayor, menor);

    if(cantPositivos>=2){
        printf("\nSe ingresaron 2 o más positivos");
    } else if(cantPositivos == 1){
        printf("\nSolo se ingreso 1 positivo");
    } else{
        printf("\nNo se ingreso ningun positivo");
    }

    return 0;
}
