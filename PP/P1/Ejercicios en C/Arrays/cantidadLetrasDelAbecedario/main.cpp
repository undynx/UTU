#include <iostream>

using namespace std;

int main()
{
    int cant[26], mayor, posMayor;
    char frase, letra = 'a';

    for(int pos = 0; pos<26 ; pos++) {
        cant[pos] = 0;
    }

    printf("Ingresa una frase: ");
    frase = getchar();

    while(frase != '\n'){
        if(frase>='a' && frase<='z'){
            frase = frase - 'a' + 'A';
        }
        cant[frase - 'A'] = cant[frase - 'A'] + 1;
        frase = getchar();
    };

    mayor = cant[0];
    for(int pos = 0; pos < 26; pos++) {

        if(cant[pos] != 0){
            printf("%c %d \n", letra + pos, cant[pos]);
        }

        if(cant[pos] > mayor) {
            mayor = cant[pos];
            posMayor = pos;
        }
    }

    printf("\nLa letra que mas se repite es la %c, unas %d veces\n", posMayor + 'A', mayor);

    return 0;
}
