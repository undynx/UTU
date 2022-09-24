#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numUser, denominator = 1, counter = 0;
    printf("Ingresa un numero para saber sus divisores: ");
    scanf("%d", &numUser);

    while (numUser >= denominator) {

        if (numUser % denominator == 0) {

            printf("%d \n", denominator);
            counter = counter + 1;
        }
        denominator = denominator + 1;
    }

    if (counter == 2) {

        printf("%d es primo", numUser);
    } else {

        printf("%d no es primo \n", numUser);
    }

    return 0;
}
