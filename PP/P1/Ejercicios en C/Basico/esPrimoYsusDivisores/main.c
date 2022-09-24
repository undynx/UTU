int main()
{

    // int main() sería el "Inicio"

    int numero, div, contDivisor, numeroUser;
    printf("Ingrese un numero mayor a 0: ");
    scanf("%d", &numeroUser);

    numero = 0;
    while (numero <= numeroUser)
    {

        div = 1;
        contDivisor = 0;

        while (div <= numero)
        {
            if (numero % div == 0)
            {
                contDivisor = contDivisor + 1;
            }

            div = div + 1;
        }

        if (contDivisor == 2)
        {
            printf("%d\n", numero);
        }
        numero = numero + 1;
    }

    return 0;
}
