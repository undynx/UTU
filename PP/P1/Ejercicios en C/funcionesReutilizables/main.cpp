#include <iostream>

///Lee lo ingresado en consola hasta el tamaño deseado, luego sigue leyendo para limpiar el buffer;
void leer_linea(char arr[],int tam){
    int pos=-1;
    do{
        if(pos<tam-1)
            pos++;
        arr[pos]=getchar();
    }while(arr[pos]!='\n');
    arr[pos]='\0';
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
