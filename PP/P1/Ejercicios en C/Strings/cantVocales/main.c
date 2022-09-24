#include <stdio.h>
#include <stdlib.h>

int main()
{
    char frase;
    int cantA = 0, cantE = 0, cantI = 0, cantO = 0, cantU = 0, cantPalabras = 1;
    printf("Ingresa una frase para saber la cantidad de vocales y palabras: ");

    do {

        frase = getchar();

        switch(frase){
            case 'a':
                cantA = cantA + 1;
            break;
            case 'e':
                cantE = cantE + 1;
            break;
            case 'i':
                cantI = cantI + 1;
            break;
            case 'o':
                cantO = cantO + 1;
            break;
            case 'u':
                cantU = cantU + 1;
            break;
            case ' ':
                cantPalabras = cantPalabras + 1;
            break;
        }

    } while (frase != '\n');

    printf("\nLa cantidad de A es: %d", cantA);
    printf("\nLa cantidad de E es: %d", cantE);
    printf("\nLa cantidad de I es: %d", cantI);
    printf("\nLa cantidad de O es: %d", cantO);
    printf("\nLa cantidad de U es: %d", cantU);
    printf("\nLa cantidad de palabras es: %d", cantPalabras);


    return 0;
}
