#include <stdio.h>
#include <stdlib.h>

int main()
{
    char array[100] = {}, text;
    int charNumber = -1;
    printf("Ingresa una frase y te digo si es palindromo\n");


    do {
        array[100] = getchar();
        charNumber = charNumber + 1;
    } while (text != '\n');

    printf("%d", charNumber);
    printf("%s", array[]);

    return 0;
}
