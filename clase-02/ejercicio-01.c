#include <stdio.h>

/*
Función: determinarCalificacion
Descripción:
Dado un puntaje (0 a 100), devuelve:
A (90-100)
B (80-89)
C (70-79)
D (60-69)
F (0-59)
*/
// determinar_calificacion -> python
char determinarCalificacion(int puntaje)
{
    char nota;

    if (puntaje >= 90 && puntaje <= 100)
        nota = 'A';
    else if (puntaje >= 80)
        nota = 'B';
    else if (puntaje >= 70)
        nota = 'C';
    else if (puntaje >= 60)
        nota = 'D';
    else
        nota = 'F';

    return nota;
}

/*
Pruebas unitarias
Retorna:
0 → OK
1 → ERROR
*/
int test_calificacion()
{
    // A
    if (determinarCalificacion(90) != 'A') return 1;
    if (determinarCalificacion(100) != 'A') return 1;

    // B
    if (determinarCalificacion(80) != 'B') return 1;
    if (determinarCalificacion(89) != 'B') return 1;

    // C
    if (determinarCalificacion(70) != 'C') return 1;
    if (determinarCalificacion(79) != 'C') return 1;

    // D
    if (determinarCalificacion(60) != 'D') return 1;
    if (determinarCalificacion(69) != 'D') return 1;

    // F
    if (determinarCalificacion(0) != 'F') return 1;
    if (determinarCalificacion(59) != 'F') return 1;

    return 0;
}

int main()
{
    if (test_calificacion() == 0)
    {
        printf("Todos los tests pasaron correctamente ✅\n");
    }
    else
    {
        printf("Error en los tests ❌\n");
    }

    return 0;
}