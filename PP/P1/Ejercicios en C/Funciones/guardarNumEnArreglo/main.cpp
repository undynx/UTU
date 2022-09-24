#include <iostream>

using namespace std;

int guardar_En_Arreglo(int arr[], int largo){

    int numUsr, saved = 0;

    for(int i=0 ; i<largo ; i++){
        printf("Ingresa un numero: ");
        scanf("%d", &numUsr);

        if(numUsr >= 0){
            arr[i] = numUsr;
            saved++;
        } else {
            i=largo;
        }
    }

    return saved;
}

int main()
{
    int enteros[20], saved;
    saved = guardar_En_Arreglo(enteros, 20);

    for(int i=0 ; i<saved ; i++){
        printf("%d | ", enteros[i]);
    }
    printf("\nSe guardaron %d numeros", saved);



    return 0;
}
