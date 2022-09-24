#include <stdio.h>
#include <stdlib.h>

int main(){

    char frase, vocalNueva = ' ';
    int cantCambios = 0, cantEspacios = 0, salto = 1;

    do {
        frase = getchar();

        switch(frase){
            case 'a': case 'e': case 'i': case 'o': case 'u':
                printf("%c", vocalNueva);
                vocalNueva = frase;
                cantCambios = cantCambios + 1;
            break;
            case ' ':
                cantEspacios = cantEspacios + 1;
                if (cantEspacios == salto) {
                    printf("\n");
                    salto = salto + 1;
                    cantEspacios = 0;
                }
            break;
            default:
                printf("%c", frase);
            break;
        }
    } while (frase != '\n');
    printf("Se cambiaron %d vocales", cantCambios);

    return 0;
}
