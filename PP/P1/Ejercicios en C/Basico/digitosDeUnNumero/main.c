#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numUser, resultado, divisor, resto;

    printf("Ingresa un numero: ");
    scanf("%d", &numUser);



    while (divisor>=1) {

        resultado = numUser/divisor;
        numUser = numUser%divisor;
        printf("  %d", resultado);
        divisor = divisor/10;

    }

    return 0;
}
