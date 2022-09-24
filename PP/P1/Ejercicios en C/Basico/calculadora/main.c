#include <stdio.h>
#include <stdlib.h>

int main()
{
    int operacion, num1, num2, resultado;

    while (1==1) {

        printf("Ingresa la operacion que quieras realizar: \n 1. si queres sumar \n 2. si queres restar \n 3. si queres multiplicar \n 4. si queres dividir \n y 5. si queres elevar un numero al cuadrado \n");
        scanf("%d", &operacion);
        printf("Ingresa el primer valor de la operacion: \n");
        scanf("%d", &num1);

        if (operacion == 5) {
            resultado = num1 * num1;

        } else {
            printf("Ahora ingresa el segundo valor: \n");
            scanf("%d", &num2);

            if (operacion == 1) {
                resultado = num1 + num2;

            } else {
                if (operacion == 2) {
                    resultado = num1 - num2;

                } else {

                    if (operacion == 3) {
                        resultado = num1 * num2;

                    } else {
                        if (operacion == 4) {
                            resultado = num1 / num2;
                        }
                    }
                }
            }
        }
        printf("El resultado es %d \n //////////// \n", resultado);
    }

    return 0;
}
