#include <stdio.h>

using namespace std;

int main()
{
    char lineaAnt[20], lineaAct[20], frase;
    int topeAnt = 0, topeAct = -1, pos;


    printf("Ingresa una linea de texto de menos de 20 caracteres: \n");

    do{
        //cambia el array actual para que sea el anterior
        for(pos=0 ; pos<topeAct ; pos++) {
            lineaAnt[pos] = lineaAct[pos];
        }
        topeAnt = topeAct;

        //escanea la frase, si esta antes que la posicion 20 la guarda, sino solo la lee
        frase = getchar();
        topeAct=0;
        while(frase != '\n') {
            if(topeAct<20) {
                lineaAct[topeAct] = frase;
                topeAct++;
            }
            frase = getchar();
        }

        //si los topes no son iguales, la frase ya no será igual
        if(topeAct == topeAnt){
            pos=0;
            //mientras lo que este en la linea actual y la anterior en pos sea igual, pos sigue aumentando
            while(pos < topeAct && lineaAct[pos] == lineaAnt[pos]){
                pos++;
            }
        } else {
            pos=-5;
        }

    }while(pos<topeAnt);
    printf("Pusiste dos iguales");

    return 0;
}
