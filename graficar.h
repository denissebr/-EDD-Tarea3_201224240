#include "arbol.h"

class graficar
{
private:
    FILE *grafica;
public:
    graficar(arbol *arbol_n);
    void graficar_nodos_arbol(nodoarbol *arbol, std::string id);
    void relacionar_nodos_arbol(nodoarbol *arbol, std::string id);
};

