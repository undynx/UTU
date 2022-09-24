#include <iostream>

int multiplicarSumando(int a, int b){

    int result;

    if(a>0){
        result = b + multiplicarSumando(a-1, b);
    }else{
        result = 0;
    }

    return result;
}

int main()
{
    int resultado;

    resultado = multiplicarSumando(2, 5);
    printf("El resultado es %d", resultado);

    return 0;
}
