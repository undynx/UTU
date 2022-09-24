#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numUser, denominator = 1;
    printf("Ingresa un numero para saber sus divisores: ");
    scanf("%d", &numUser);

    while (numUser >= denominator) {

        if (numUser % denominator == 0) {

            printf("%d \n", denominator);
        }
        denominator = denominator + 1;
    }

    return 0;
}
