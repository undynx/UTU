#include <stdio.h>
#include <stdlib.h>

int main()
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
}
