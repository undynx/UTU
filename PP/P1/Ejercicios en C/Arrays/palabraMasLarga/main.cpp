#include <stdio.h>

using namespace std;

int main()
{
    char frase[100], letra;
    int cantLetras = 0, mayor = 0, tope = 0, pos;

    printf("Ingresá una frase y devuelvo la palabra más larga\n");

    letra = getchar();

    //guardo el arreglo
    while(letra != '\n' && pos<100){
        frase[pos] = letra;
        letra = getchar();
        pos++;
    }
    tope=pos;

    //lo imprimo para probar
    for(pos=0 ; pos<tope ; pos++) {
        printf("%c", frase[pos]);
    }
    printf("\n%d", tope);

    for(pos=0 ; pos<tope ; pos++) {
        if(frase[pos] != ' '){
            cantLetras++;
        } else if(cantLetras > mayor) {
            mayor = cantLetras;
        }
    }


    /*do{
        while(frase[pos] != ' '){
            cantLetras++;
            pos++;
        }
        if(cantLetras > mayor){
            mayor = cantLetras;
        }
        cantLetras = 0;
        pos++;
    }while(pos<=tope);*/

    /*do{
        while(frase[pos] != ' '){
            cantLetras++;
        }
        if(cantLetras > mayor){
            mayor = cantLetras;
        }
        pos++;
    }while(pos<tope);*/


    /*cantLetras=0;
    pos=0;
    while(frase[pos] != ' '){
        cantLetras++;
        pos++;
    }
    if(cantLetras > mayor) {
        mayor = cantLetras;
    }*/


    return 0;
}
