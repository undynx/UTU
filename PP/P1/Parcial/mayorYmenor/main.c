#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numMayor, numMenor, numUser;
    printf("Ingresa numeros para saber cual es el mayor");
    printf("\nCuando quieras dejar de ingresar, ingresa 999 \n");
    scanf("%d", &numUser);
    numMayor = numUser;
    numMenor = numUser;

    while (numUser != 999) {


        if (numUser > numMayor) {
            numMayor = numUser;
        }

        if (numUser < numMenor) {
            numMenor = numUser;
        }

        printf("Ingresa otro numero: \n");
        scanf("%d", &numUser);

    }

    printf("\nEl numero mayor es %d y el menor es %d", numMayor, numMenor);

    return 0;
}
