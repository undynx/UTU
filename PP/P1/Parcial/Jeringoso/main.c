#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf ("Ingresa una frase: ");
    char frase;
    int contadorPalabras = 0, contadorCambios = 0;

    do {
        frase = getchar();

        switch(frase) {
            case 'a':
                printf("%cp%c", frase, frase);
                contadorCambios = contadorCambios + 1;
            break;
            case 'e':
                printf("%cp%c", frase, frase);
                contadorCambios = contadorCambios + 1;
            break;
            case 'i':
                printf("%cp%c", frase, frase);
                contadorCambios = contadorCambios + 1;
            break;
            case 'o':
                printf("%cp%c", frase, frase);
                contadorCambios = contadorCambios + 1;
            break;
            case 'u':
                printf("%cp%c", frase, frase);
                contadorCambios = contadorCambios + 1;
            break;
            case ' ':
                contadorPalabras = contadorPalabras + 1;
            break;
            default:
                printf("%c", frase);
            break;
        }


    } while(frase != '\n');




    return 0;
}


/*int main()
{
    printf("Ingresa una frase y cuento cuantas palabras tiene. Para terminar pone un punto :)\n");

    int amountofWords = 1;
    char text;

    do {
        text = getchar();

        if (text == ' ' || text == '\n') {
            amountofWords = amountofWords + 1;
        }

    } while(text != '.');

    printf("\nIngresaste %d palabras", amountofWords);

    return 0;
}*/
