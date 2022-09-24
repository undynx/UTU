#include <iostream>

using namespace std;


int factorial(int num){

    int result;

    if(num==0){
        printf("Llega aca?\n");
        result = 1;
    } else {
        printf("%d \n", num);
        result = num * factorial(num-1);
    }

    return result;
}

int main()
{

    int print;
    print = factorial(5);
    printf("El resultado es: %d", print);

    return 0;
}
