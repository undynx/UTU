#include <stdio.h>

using namespace std;

int main()
{
    char palabra[5], frase[100];
    int posPalabra = 0, posFrase = -1, cantPalabra=0;
    /*posFrase está en -1 para simplificar el do while,
    porque primero aumenta la variable, y si la inicializara en 0
    no contaría la posición 0*/

    printf("Ingresa una palabra de 5 caracteres");
    //escaneo la palabra, asumiendo que solo tiene 5 letras
    for(posPalabra=0 ; posPalabra < 5 ; posPalabra++){
        palabra[posPalabra] = getchar();
    };
    getchar(); //se realiza para eliminar el enter

    printf("Ingresa una linea de hasta 100");
    do{
        posFrase++;
        frase[posFrase] = getchar();
    } while(frase[posfrase] != '\n');

    posFrase = 0;
    while(frase[posFrase] != '\n'){
        posPalabra = 0;
        for(posFrase ; posFrase<100 ; posFrase++){

        }

    }



    return 0;
}
