#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numUser, digito, binario=0, mult=1;

    printf("Ingrese un número: ");
    scanf("%d", &numUser);

    printf("Ahora en binario: ");
    while(numUser>0){

        digito=numUser%2;

        digito=digito*mult;
        binario=binario+digito;

        mult=mult*10;
        numUser=numUser/2;
    }
    printf("%d", binario);


    return 0;
}
