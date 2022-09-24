#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));

    char matrix[10][10], letter;
    int matrixSize, pos1, pos2;

    for(pos1=0 ; pos1<10 ; pos1++){
        for(pos2=0 ; pos2<10 ; pos2++){
            matrix[pos1][pos2] = ' ';
        }
    }

    printf("Ingresa el tamaño de la matriz, debe ser menor a 10 y mayor a 5: ");
    scanf("%d", &matrixSize);
    while(matrixSize>10 || matrixSize<5){
        printf("Ingresa el tamaño de la matriz, debe ser menor a 10 y mayor a 5: ");
        scanf("%d", &matrixSize);
    }

    for(int i=0 ; i<matrixSize ; i++){
        getchar();
        printf("Ingresa la letra que desees agregar: ");
        scanf("%c", &letter);

        do{
            pos1 = rand()%matrixSize;
            pos2 = rand()%matrixSize;
        }while(matrix[pos1][pos2] != ' ');

        matrix[pos1][pos2] = letter;
    }

    for(pos1=0 ; pos1<matrixSize ; pos1++){
        for(pos2=0 ; pos2<matrixSize ; pos2++){
            printf(" %c |", matrix[pos1][pos2]);
        }
        printf("\n");
    }


    return 0;
}
