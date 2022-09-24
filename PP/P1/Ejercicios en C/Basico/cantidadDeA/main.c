#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letra;
    int contadorA = 0, contadorE = 0, contadorI = 0, contadorO = 0, contadorU = 0, contador = 0;
    printf("Ingresa letras y cuento la cantidad de vocales que tiene: \n");

    do {

        letra = getchar();

        switch(letra){
            case 'a':
                contadorA = contadorA + 1;
            break;
            case 'e':
                contadorE = contadorE + 1;
            break;
            case 'i':
                contadorI = contadorI + 1;
            break;
            case 'o':
                contadorO = contadorO + 1;
            break;
            case 'u':
                contadorU = contadorU + 1;
            break;
        }

        contador = contador + 1;

    } while(contador < 20);

    printf("\nHay %d letras a", contadorA);
    printf("\nHay %d letras e", contadorE);
    printf("\nHay %d letras i", contadorI);
    printf("\nHay %d letras o", contadorO);
    printf("\nHay %d letras u", contadorU);

    return 0;
}
