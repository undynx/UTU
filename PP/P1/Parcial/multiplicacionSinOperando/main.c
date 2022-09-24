#include <stdio.h>
#include <stdlib.h>

int main()
{
    int multiplicado, multiplicador, resultado;
    printf("Ingresa dos numeros que desees que sean multiplicados\n");
    printf("Multiplicador: ");
    scanf("%d", &multiplicador);
    printf("Multiplicado: ");
    scanf("%d", &multiplicado);
    resultado = multiplicado;

    while (multiplicador > 1) {
        resultado = resultado + multiplicado;
        multiplicador = multiplicador - 1;
    }

    printf("%d", resultado);

    return 0;
}
