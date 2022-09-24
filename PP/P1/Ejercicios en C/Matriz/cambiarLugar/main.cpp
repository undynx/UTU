#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    int matriz[3][3];
    int pasamano, vidas, pos1, pos2, fila, columna;
    srand(time(NULL));


    for(pos1=0 ; pos1<3 ; pos1++) {
        for(pos2=0 ; pos2<3 ; pos2++) {
            matriz[pos1][pos2] = rand()%10;
        }
    }

    for(pos1=0 ; pos1<3 ; pos1++) {
        for(pos2=0 ; pos2<3 ; pos2++) {
            printf(" %d |", matriz[pos1][pos2]);
        }
        printf("\n");
    }

    printf("\nDebes ordenar esta matriz, intercambiando sus elementos con el primer elemento");

    for(vidas=10; vidas>0; vidas--){
        printf("\n\nTe quedan %d intentos", vidas);
        printf("\nElegi la fila (del 0 al 2): ");
        scanf("%d", &pos1);
        while(pos1>2 || pos1<0){
            printf("La fila debe estar entre 0 y 2");
            printf("\nElegi la fila (del 0 al 2): ");
            scanf("%d", &pos1);
        }
        printf("Elegi la columna (del 0 al 2): ");
        scanf("%d", &pos2);
        while(pos2>2 || pos2<0){
            printf("La columna debe estar entre 0 y 2");
            printf("\nElegi la fila (del 0 al 2): ");
            scanf("%d", &pos2);
        }
        pasamano = matriz[0][0];
        matriz[0][0] = matriz[pos1][pos2];
        matriz[pos1][pos2] = pasamano;

        for(pos1=0 ; pos1<3 ; pos1++) {
            for(pos2=0 ; pos2<3 ; pos2++) {
                printf(" %d |", matriz[pos1][pos2]);
            }
            printf("\n");
        }
    }
    //te quiero mucho
    int result=0, previo=0;

    for(pos1=0 ; pos1<3 ; pos1++) {
        for(pos2=0 ; pos2<3 ; pos2++) {
            if(matriz[pos1][pos2] >= previo){
                result++;
                previo = matriz[pos1][pos2];
            }
        }
    }

    printf("\nHiciste %d puntos", result);

    return 0;
}
