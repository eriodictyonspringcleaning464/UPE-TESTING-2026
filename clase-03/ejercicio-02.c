#include <stdio.h>

int SumaParesPositivos(int , int );

int main(){
    
    int resultado = SumaParesPositivos(3,5);
    printf("Resultado: %d", resultado);
    
    return 0;
}

int SumaParesPositivos(int a, int b)
{
    int suma = 0;
    int x;

    for (x = a; x <= b && x != -1; x++)
    {
        if (x % 2 == 0)
        {
            suma += x;
        }
    }

    return suma;
}
