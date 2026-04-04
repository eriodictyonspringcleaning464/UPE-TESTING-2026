#include <stdio.h> 

int test();
int funcion_suma(int, int); // caja negra

int main()
{
    if(test()) {
        //camino True
        printf("Error\n");
    } else {
        //camino False
        printf("Todo ok main\n");
    }

    return 0;
}

int test(){
    //suma de 2 enteros
    if(funcion_suma(2, 3) == 5){
        //TODO OK
        printf("test 01 ok\n");
    } else {
        //ERROR
        return 1;
    }
    //suma de 2 enteros
    if(funcion_suma(6, 3) == 9){
        printf("test 02 ok\n");
    } else {
        //ERROR
        return 1;
    }
    //suma de 1 entero negativo y un entero positivo
    if(funcion_suma(-2, 2) == 0){
        printf("test 03 ok\n");
    } else {
        //ERROR
        return 1;
    }
    //suma de 2 enteros negativos
    if(funcion_suma(-2, -2) == -4){
        printf("test 04 ok\n");
    } else {
        //ERROR
        return 1;
    }
    //suma de 2 enteros negativos
    if(funcion_suma(1000000000, 1000000000) == 2000000000){
        printf("test 05 ok\n");
    } else {
        //ERROR
        return 1;
    }

    return 0;
}






// caja negra: no sabemos su implementación, solo sabemos su comportamiento (inputs y outputs)
int funcion_suma(int a, int b){
    return a + b;
}