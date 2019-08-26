#include <iostream>
#include <stdlib.h>
#include "arbol.h"

using namespace std;

int main(){
    int opcion = 0;
    arbol *arbol_n = new arbol();
    while (opcion != 4)
    {
        printf("Seleccione una opcion\n");
        printf("1. Insertar\n");
        printf("2. Eliminar\n");
        printf("3. Graficar\n");
        printf("4. Salir\n");
        std::cin >> opcion;
        if(opcion == 1){
            std::string valor;
            printf("Ingrese el valor a guardar:\n");
            std::cin >> valor;
            nodoarbol *nodo = new nodoarbol(valor);
            arbol_n->Insertar_arbol(nodo);
        }else if(opcion == 2){
            printf("Ingrese el valor a eliminar:\n");
            std::string valor;
            std::cin >> valor;
            arbol_n->Eliminar(valor);
        }
    }
    return 1;
}