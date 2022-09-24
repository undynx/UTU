#include <iostream>

int fibonacci(int conteo){
    int num=1;

    if(conteo==0){
        printf("0 \n");
    }else{
        printf("%d \n", num);
        conteo--;
        num = fibonacci(num-1) + fibonacci(num-2);
    }

    return num;
}

int main()
{

    fibonacci(15);

    return 0;
}
