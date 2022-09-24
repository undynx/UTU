#include <stdio.h>

using namespace std;

int main()
{
    char palabra[5], frase;
    int cantidad[5], menor;
    printf("Ingresa una palabra de 5 caracteres: ");

    for(int pos = 0; pos<5; pos++) {
        palabra[pos] = getchar();
        cantidad[pos] = 0;
    }

    printf("\nAhora ingresa una frase: ");
    frase = getchar();

    do{
        frase = getchar();
        for(int pos=0 ; pos<5 ; pos++) {
            if(palabra[pos] == frase) {
                cantidad[pos] = cantidad[pos] + 1;
            }
        }
    }while(frase != '\n');

    menor = cantidad[0];

    for(int pos=0 ; pos<5 ; pos++) {
        printf("%c %d / ", palabra[pos], cantidad[pos]);

        if(cantidad[pos] < menor) {
            menor = pos;
        }
    }

    printf("\n\nSe puede imprimir %d veces\n", cantidad[menor]);

    return 0;
}
