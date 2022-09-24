#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valorA, valorB, valorC, diferenciaCB, diferenciaBA, cantDivisores = 0, divisor=2;

    printf("Ingresa un valor inicial: ");
    scanf("%d", &valorA);
    printf("Y otro ma que sea mayor: ");
    scanf("%d", &valorB);

    do{

       printf("Ingresa un valor para ser comparado: ");
       scanf("%d", &valorC);
       diferenciaCB = valorC - valorB;
       diferenciaBA = valorB - valorA;

        while(divisor < diferenciaCB && divisor == 0) {
            if(diferenciaCB % divisor == 0){
                if(diferenciaBA % divisor == 0) {
                    cantDivisores = cantDivisores + 1;
                }
            }
            divisor = divisor + 1;
        }

        if(cantDivisores >= 1) {
            valorA = valorB;
            valorB = valorC;
            printf("Ingresa otro numero");
            scanf("%d", &valorC);
        } else {
            printf("Perdiste");
            cantDivisores = 0;
        }


    } while(cantDivisores != 0);

    return 0;
}
