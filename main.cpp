#include <stdlib.h>
#include <stdio.h>
#include <iostream>

int main(){
    int opcion = 0;
    while (opcion != 3)
    {
        printf("Seleccione una opcion\n");
        printf("1. Insertar\n");
        printf("2. Eliminar\n");
        printf("3. Salir\n");
        std::cin >> opcion;
    }
    return 1;
}