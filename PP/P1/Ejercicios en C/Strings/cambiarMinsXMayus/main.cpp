#include <stdio.h>

using namespace std;

int main()
{
    char digito;
    printf("Ingresa letras y las cambio\n");

    do {

        digito = getchar();

        if (digito >= 'A' && digito <= 'Z'){
            printf("%c ", digito+33);
        } else if (digito >= 'a' && digito <= 'z') {
            printf("%c ", digito-31);
        }

    } while(digito != '\n');

    return 0;
}
