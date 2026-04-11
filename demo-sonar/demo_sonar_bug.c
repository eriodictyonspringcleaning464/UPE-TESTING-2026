#include <stdio.h>

/*
 Demo simple para SonarQube:
 - posible uso de variable no inicializada
 - código muerto / condición contradictoria
 - lógica poco clara para mostrar issues
*/

int calcularDivisionSegura(int a, int b)
{
    int resultado = 0;   // potencialmente no inicializada

    if (b != 0)
    {
        resultado = a / b;
    }

    return resultado; // si b == 0, puede devolver basura
}

int main(void)
{
    int r1 = calcularDivisionSegura(10, 2);
    int r2 = calcularDivisionSegura(10, 0);

    printf("Resultado 1: %d\n", r1);
    printf("Resultado 2: %d\n", r2);

    return 0;
}