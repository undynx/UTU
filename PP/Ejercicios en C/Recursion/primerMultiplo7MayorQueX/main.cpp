#include <iostream>

using namespace std;

int primerMultiplo7(int num){

    int result;

    if(num%7==0){
        result = num;
    }else{
        result = primerMultiplo7(num+1);
    }

    return result;
}

int main()
{
    int result;
    result = primerMultiplo7(1254);
    printf("El primero es %d", result);

    return 0;
}
