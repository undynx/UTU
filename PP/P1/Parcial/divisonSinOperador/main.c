#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dividendo, divisor, resultado, contador, resto;
    printf("Ingresa dos numeros que desees que sean divididos\n");
    printf("Dividendo: ");
    scanf("%d", &dividendo);
    printf("Divisor: ");
    scanf("%d", &divisor);
    contador = 0;

    while (dividendo >= divisor) {
        dividendo = dividendo - divisor;
        contador = contador + 1;
    }

    printf("%d", contador);
    if (dividendo < divisor) {
        printf("\nEl resto es %d", divisor - 1);
    }

    return 0;
}
