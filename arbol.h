#include "nodoarbol.h"
#include <string.h>
#include <iostream>

class arbol
{
private:
    /* data */
    nodoarbol *raiz;
public:
    arbol(/* args */);
    void Insertar_arbol(nodoarbol *nuevo);
    nodoarbol *getRaiz();
    bool Existe_n(std::string nombre, nodoarbol *auxraiz);
};