#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numUser = 0;
    printf("Ingresa un numero para saber si es divisible entre 3 y/o 5: ");
    scanf("%d", &numUser);

    if (numUser % 3 == 0) {

        if (numUser % 5 == 0) {

            printf("%d es divivible entre 3 y 5", numUser);
        } else {

            printf("%d es divisible entre 3", numUser);
        }

    } else {

        if (numUser % 5 == 0) {

            printf("%d es divisible entre 5", numUser);
        } else {

            printf("%d no es divisible ni entre 3 ni entre 5", numUser);
        }

    }

    return 0;
}
