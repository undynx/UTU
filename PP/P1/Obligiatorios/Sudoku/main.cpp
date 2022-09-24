#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

// PARTICIPANTES //
// Maité Martínez - 5.142.074-8
// María Mendoza - 6.263.316-6

//Variables Globales//
const int tam = 9, cantVueltas = 10000;

/*//*//*//*//*//*//*//*//*//*//*//*/

//Declaración de Funciones//

///Inicializa el Sudoku 's' llenando todas las celdas con el valor 0.
void inicializar_sudoku (int s[][tam]);

///Imprime el Sudoku en pantalla con un formato matricial mostrando la separación entre regiones.
void imprimir_sudoku (int s[][tam]);

///Genera aleatoriamente un nuevo Sudoku ‘s’ con la cantidad de elementos ‘cant_elem’.
void generar_sudoku_valido (int s[][tam], int cantElem);

///Ingreso una coordenada de region y devuelve la posicion inicial de esa region
int posicion_region(int num);

///Devuelve true si ‘num’ es candidato para la celda del Sudoku ‘s’ dada por ‘fila’ y ‘columna’
bool es_candidato (int s [][9], int num, int fila, int columna);

///Ingreso fila y columna y encuentra los candidatos para esa celda vacia
void crear_candidatos (int s[][9], int fila, int columna, bool candidatos[][tam][tam]);

///Recibe una region y actualiza el valor del comienzo en fila y columna
void comienzo_region(int reg, int &comienzoFila, int &comienzoColumna);

///Devuelve true si el tablero ‘s’ cumple con los requisitos de un Sudoku válido
bool sudoku_valido (int s[][9]);

///Devuelve true si el tablero está completamente resuelto, o false en caso contrario.
bool sudoku_resuelto (int s [9][9]);

/*//*//*//*//*//*//*//*//*//*//*//*/


int main()
{
    srand(time(NULL));
    int sudoku[tam][tam], cantElemInicial;

    inicializar_sudoku(sudoku);
    printf("Cuantos elementos queres agregar?: ");
    scanf("%d", &cantElemInicial);
    generar_sudoku_valido(sudoku, cantElemInicial);
    imprimir_sudoku(sudoku);

    //Descomentar esto para probar la funcion crear_candidatos()
    /*int filaCandidatos, columnaCandidatos;
    printf("\nDe que lugar deseas saber los candidatos? 1 significa que es candidato, 0 significa que no lo es");
    printf("\nIngresa la fila: ");
    scanf("%d", &filaCandidatos);
    printf("Ingresa la columna: ");
    scanf("%d", &columnaCandidatos);
    crear_candidatos(sudoku, filaCandidatos, columnaCandidatos, candidatos);
    for(int i=1;i<=tam;i++)
        printf("%d: %d \n", i, candidatos[filaCandidatos][columnaCandidatos][i]);*/


    //Decomentar esto para probar la funcion es_candidato()
    /*int numCandidato, filaCandidato, columnaCandidato;
    bool esCandidato;
    printf("Que numero deseas saber si es candidato? 1 significa que lo es, 0 significa que no lo es: ");
    scanf("%d", &numCandidato);
    printf("De que fila?: ");
    scanf("%d", &filaCandidato);
    printf("De que columna?: ");
    scanf("%d", &columnaCandidato);
    esCandidato = es_candidato(sudoku, numCandidato, filaCandidato, columnaCandidato);
    printf("%d es candidato?: %d", numCandidato, esCandidato);*/

    return 0;
}


/*//*//*//*//*//*//*//*//*//*//*//*/

// Definición de Funciones //

///Inicializa el Sudoku 's' llenando todas las celdas con el valor 0.
void inicializar_sudoku (int s[][tam]){

    for(int pos1=0 ; pos1<tam ; pos1++)
        for(int pos2=0 ; pos2<tam ; pos2++)
            s[pos1][pos2] = 0;
}

///Imprime el Sudoku en pantalla con un formato matricial mostrando la separación entre regiones.
void imprimir_sudoku (int s[][tam]){

    for(int pos1=0 ; pos1<tam ; pos1++){
        for(int pos2=0 ; pos2<tam ; pos2++){
            if(pos2 == 2 || pos2 == 5)
                printf(" %d |  |", s[pos1][pos2]);
            else
                printf(" %d |", s[pos1][pos2]);
        }
        if(pos1 == 2 || pos1 == 5)
                printf("\n\n");
            else
                printf("\n");
    }
}

///Genera aleatoriamente un nuevo Sudoku ‘s’ con la cantidad de elementos ‘cant_elem’.
void generar_sudoku_valido (int s[][tam], int cantElem){

    int numRandom, lineRandom, columnRandom, vueltas=0;
    bool stop=false, esCandidato;

    while(cantElem > 0){

        //Lo repite hasta encontrar una combinacion valida
        do{
            numRandom = rand()%9+1;
            //Genera un nuevo numero y ubicacion random para cada pasada sin sobreescribir a menos que sea cero
            do{
                lineRandom = rand()%9;
                columnRandom = rand()%9;
                vueltas++;

                //Para el bucle si este se ejecuta muchas veces
                if(vueltas>cantVueltas){
                    stop = true;
                    inicializar_sudoku(s);
                }
            }while(s[lineRandom][columnRandom]!=0 && stop==false);

            esCandidato = es_candidato(s, numRandom, lineRandom, columnRandom);

        }while(esCandidato == false);

        //Me aseguro de que el ultimo numero que ingrese sea 0
        if(vueltas>cantVueltas)
            numRandom=0;

        //Ubica el numero random en la ubicacion random obtenida
        s[lineRandom][columnRandom] = numRandom;
        cantElem--;
    }
}

///Ingreso una coordenada de region y devuelve la posicion inicial de esa region
int posicion_region(int num){

    int posInicial;

    switch(num){
        case  0: case 1: case 2:
            posInicial = 0;
        break;
        case 3: case 4: case 5:
            posInicial = 3;
        break;
        case 6: case 7: case 8:
            posInicial = 6;
        break;
    }

    return posInicial;
}

///Devuelve true si ‘num’ es candidato para la celda del Sudoku ‘s’ dada por ‘fila’ y ‘columna’
bool es_candidato (int s [][9], int num, int fila, int columna){

    bool esCandidato = true, estaEnFila = false, estaEnColumna = false, estaEnRegion = false;

    //Verifica si el numero esta en la fila
    for(int i=0 ; i<tam ; i++){
        if(s[fila][i] == num)
            estaEnFila = true;
    }

    //Verifica si el numero está en la columna
    for(int i=0 ; i<tam ; i++){
        if(s[i][columna] == num)
            estaEnColumna = true;
    }

    //Verifico si el numero está en la región
    //Primero obtengo el valor inicial de la region (fila y columna)
    int inicioLineReg = posicion_region(fila);
    int inicioColumnReg = posicion_region(columna);

    for(int pos1=inicioLineReg ; pos1<=inicioLineReg+2 ; pos1++){
        for(int pos2=inicioColumnReg ; pos2<=inicioColumnReg+2 ; pos2++){
            if(s[pos1][pos2] == num){
                estaEnRegion = true;
            }
        }
    }

    if(estaEnFila || estaEnColumna || estaEnRegion)
        esCandidato = false;

    return esCandidato;

}

///Ingreso fila y columna y encuentra los candidatos para esa celda vacia
void crear_candidatos (int s[][9], int fila, int columna, bool candidatos[][tam][tam]){

    for(int i=1 ; i<=tam ; i++){

        //Comienzo igualando el valor a true y si no es candidato se cambia a false
        candidatos[fila][columna][i] = true;

        if(es_candidato(s, i, fila, columna)==false){
            candidatos[fila][columna][i] = false;
        }
    }
}

///Recibe una region y actualiza el valor del comienzo en fila y columna
void comienzo_region(int reg, int &comienzoFila, int &comienzoColumna){

    switch(reg){
        case 1:
            comienzoFila = 0;
            comienzoColumna = 0;
        break;
        case 2:
            comienzoFila = 0;
            comienzoColumna = 3;
        break;
        case 3:
            comienzoFila = 0;
            comienzoColumna = 6;
        break;
        case 4:
            comienzoFila = 3;
            comienzoColumna = 0;
        break;
        case 5:
            comienzoFila = 3;
            comienzoColumna = 3;
        break;
        case 6:
            comienzoFila = 3;
            comienzoColumna = 6;
        break;
        case 7:
            comienzoFila = 6;
            comienzoColumna = 0;
        break;
        case 8:
            comienzoFila = 6;
            comienzoColumna = 3;
        break;
        case 9:
            comienzoFila = 6;
            comienzoColumna = 6;
        break;
    }

}

///Devuelve true si el tablero ‘s’ cumple con los requisitos de un Sudoku válido
bool sudoku_valido (int s[][9]){
    bool sudokuValido = true;
    int comienzoRegFila = 0, comienzoRegColumna = 0, cantRep = 0;

    //Chequeo que no se repita ningun numero en las regiones
    for(int reg=1 ; reg<=9 ; reg++){
        //Actualiza las variables segun la region en la que estoy
        comienzo_region(reg, comienzoRegFila, comienzoRegColumna);

        for(int i=1 ; i<=9 ; i++){ //elige un numero
            for(int pos1=comienzoRegFila ; pos1<=comienzoRegFila+2 ; pos1++){ //itera por la submatriz para verificar que ese numero no se repite
                for(int pos2=comienzoRegColumna ; pos2<=comienzoRegColumna+2 ; pos2++){
                    if(s[pos1][pos2] == i){
                        cantRep++;
                    }
                    if(cantRep > 1){
                        //Si un numero se repite mas de una vez, setea el sudoku como falso y las variables en 10 para salir del bucle
                        sudokuValido = false;
                        i = 10;
                        reg=10;
                    }
                }
            }
            //Setea la cantidad de repeticiones en 0 para volver a validar con el siguiente numero
            cantRep=0;
        }

    }

    //Si en el chequeo de las regiones el sudoku era invalido no realiza el chequeo por fila y columna
    if(sudokuValido){
        cantRep = 0;

        for(int i=1 ; i<=9 ; i++){ //elige un numero
            for(int pos1=0 ; pos1<9 ; pos1++){ //itera por la matriz para verificar que ese numero no se repite
                for(int pos2=0 ; pos2<9 ; pos2++){
                    if(s[pos1][pos2] == i){
                        cantRep++;
                    }
                    if(cantRep > 1){
                        //Si un numero se repite mas de una vez, setea el sudoku como falso y las variables en 10 para salir del bucle
                        sudokuValido = false;
                        i = 10;
                        pos2 = 10;
                        pos1 = 10;
                    }
                }
            }
            cantRep=0;
        }

    }

    return sudokuValido;
}

///Devuelve true si el tablero está completamente resuelto, o false en caso contrario.
bool sudoku_resuelto (int s [9][9]){
    bool resuelto = true;

    if(sudoku_valido(s)){
        for(int pos1=0 ; pos1<9 ; pos1++){
            for(int pos2=0 ; pos2<9 ; pos2++){
                if(s[pos1][pos2] == 0){
                    resuelto = false; //si alguna celda es 0, setea la variable como falsa
                    //setea las variables en 10 para salir del bucle
                    pos1 = 10;
                    pos2 = 10;
                }
            }
        }

    } else{
        resuelto = false;
    }

    return resuelto;
}
