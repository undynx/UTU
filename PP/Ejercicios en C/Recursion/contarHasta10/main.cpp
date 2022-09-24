#include <iostream>

using namespace std;

void conteo(int num){

    if(num==2){
        printf("1");
    } else {
        printf("%d \n", num-1);
        conteo(num-1);
    }
}

int main()
{
    conteo(10);

    return 0;
}
