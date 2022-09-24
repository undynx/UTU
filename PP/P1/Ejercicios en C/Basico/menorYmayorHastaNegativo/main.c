#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numMayor, numMenor, numUser;
    printf("Ingresa la cantidad de numeros que desees comparar. \nCuando no quieras agregar mas numeros, ingresa uno positivo\n");
    printf("Ingresa un numero: ");
    scanf("%d", &numUser);
    numMayor = numUser;
    numMenor = numUser;


    while (numUser >= 0) {

        printf("Ingresa un numero: ");
        scanf("%d", &numUser);

        if (numUser >= 0) {
            if (numUser > numMayor) {
            numMayor = numUser;

            } else {

                if (numUser < numMenor) {
                    numMenor = numUser;
                }
            }
        }
    }

    printf("El numero mayor es: %d", numMayor);
    printf("\nEl numero menor es: %d", numMenor);
    return 0;
}
