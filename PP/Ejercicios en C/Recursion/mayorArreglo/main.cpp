#include <iostream>

int mayor(int arr[], int tam){

    int numMay;

    if(tam==1){
        numMay = arr[0];
    } else {
        numMay=mayor(arr, tam-1);
        if(arr[tam-1] > numMay)
            numMay = arr[tam-1];
    }

    return numMay;
}

int main()
{
    int tam = 5;
    int arr[tam] = {4, 22, 9, 10, 45};

    printf("El mayor es %d", mayor(arr, tam));

    return 0;
}
