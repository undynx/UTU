#include <iostream>

void imprimir_arreglo(int arr[], int tam){

    if(tam==1){
        printf(" %d /", arr[0]);
    }else{
        imprimir_arreglo(arr, tam-1);
        printf(" %d /", arr[tam-1]);
    }

}

int main()
{
    int tam = 5;
    int arr[tam] = {4, 22, 99, 10, 45};

    imprimir_arreglo(arr, tam);

    return 0;
}
