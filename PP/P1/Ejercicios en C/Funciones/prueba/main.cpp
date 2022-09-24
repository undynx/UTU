#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    bool candidatos[9][9][9];

    candidatos[1][8][0] = true;
    candidatos[1][8][1] = false;
    candidatos[1][8][2] = true;
    candidatos[1][8][3] = true;
    candidatos[1][8][4] = false;
    candidatos[1][8][5] = false;
    candidatos[1][8][6] = false;
    candidatos[1][8][7] = true;
    candidatos[1][8][8] = true;

    //printf ("%d", candidatos[1][8][0]);

    /*for(int pos1=0 ; pos1<9 ; pos1++)
        for(int pos2=0 ; pos2<9 ; pos2++)
            */for(int i=0 ; i<9 ; i++){
                printf ("%d", candidatos[1][8][i]);
                printf("\n");
            }

    /*void crear_candidatos (int s [9][9], int fila, int columna, bool candidatos[9]);
    Dada la fila y la columna, encuentra los candidatos para esa celda vacía
    y los registra en el arreglo 'candidatos’. A modo de ejemplo
    si el conjunto de candidatos es {1,3,4,9} -->
    ‘candidatos’ = [true,false,true,true,false,false,false,false,true]*/

    return 0;
}
