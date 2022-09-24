#include <stdio.h>
#include <stdlib.h>

int main()
{

    int numA, numB, numC, numMayor, numMenor, numMedio;
    printf("Ingresa tres numeros que desees ordenar");
    printf("El primero");
    scanf("%d", &numA);
    printf("El segundo");
    scanf("%d", &numB);
    printf("El tercero");
    scanf("%d", &numC);

    if (numA > numB) {
        numMayor = numA;
        numMenor = numB;

        if (numC > numA) {
            numMayor = numC;
            numMedio = numA;
        } else {

            if (numC < numB) {
                numMenor = numC;
                numMedio = numB;
            } else {
                num
            }

        }

    } else {
        numMayor = B;
        numMenor = A;

    }



    return 0;
}
