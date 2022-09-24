#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numMayor, numMenor, numUser, repeticiones;
    repeticiones = 0;
    printf("Ingresa 5 numeros para ver el mayor y el menor\n");
    printf("Ingresa un numero: ");
    scanf("%d", &numUser);
    numMayor = numUser;
    numMenor = numUser;


    while (repeticiones < 4) {

        printf("Ingresa un numero: ");
        scanf("%d", &numUser);

        if (numUser > numMayor) {
            numMayor = numUser;
        } else {
            if (numUser < numMenor) {
            numMenor = numUser;
            }
        }

        repeticiones = repeticiones + 1;
    }

    printf("El numero mayor es: %d", numMayor);
    printf("\n");
    printf("El numero menor es: %d", numMenor);
    return 0;
}
