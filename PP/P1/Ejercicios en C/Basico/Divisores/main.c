#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numUser, divisor;

    printf("Ingresa un numero para saber sus divisores: \n");
    scanf("%d", &numUser);
    divisor = 1;

    while (divisor <= numUser) {

        if (numUser % divisor == 0) {
            printf("%d \n", divisor);
        }

        divisor = divisor + 1;

    }

    return 0;
}
