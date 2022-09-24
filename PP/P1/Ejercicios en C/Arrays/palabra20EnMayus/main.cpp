#include <stdio.h>

using namespace std;

int main()
{
    char palabra[20], letra = 'a';
    int pos = 0, tope;
    printf("Ingresa una palabra de 20 caracteres o menos:\n");

    while(letra != '\n' && pos<20){
        letra = getchar();
        palabra[pos] = letra;
        pos++;
    }
    tope = pos-1;

    printf("\nLa imprimo al derecho y en mayusculas:\n");

    for(pos = 0; pos<tope; pos++) {

        if(palabra[pos] >= 'a' && palabra[pos] <= 'z')
            palabra[pos] = palabra[pos] - 'a' + 'A';

        printf("%c", palabra[pos]);
    }

    printf("\nY ahora al reves:\n");

    for(pos=tope-1;pos>=0;pos--) {

        if(palabra[pos] >= 'a' && palabra[pos] <= 'z')
            palabra[pos] = palabra[pos] - 'a' + 'A';

        printf("%c", palabra[pos]);
    }




    return 0;
}
