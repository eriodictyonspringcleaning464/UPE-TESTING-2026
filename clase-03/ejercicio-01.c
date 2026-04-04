#include <stdio.h>

void mostrarMayor(int x, int y);

// Hola
int main(){

    mostrarMayor(1,2);

    return 0;
}


void mostrarMayor(int x, int y)
{
    if (x > y)
        printf("El mayor es: %d", x);
    else
    {
        if (y > x)
            printf("El mayor es: %d", y);
        else
            printf("Son iguales");
    }
}
