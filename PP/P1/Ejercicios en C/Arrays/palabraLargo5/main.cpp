#include <stdio.h>

using namespace std;

int main()
{
    char palabra[5];
    printf("Ingresa una palabra de 5 caracteres: ");

    for(int pos = 0; pos<5; pos++) {
        palabra[pos] = getchar();
    }

    for(int pos = 4; pos>=0; pos--) {
        printf("%c", palabra[pos]);
    }

    return 0;
}
