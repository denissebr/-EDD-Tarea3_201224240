#ifndef NODOARBOL_H
#define NODOARBOL_H

#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

class nodoarbol
{
private:
    std::string nombre;
    nodoarbol *hijoizquierdo;
    nodoarbol *hijoderecho;
public:
    
    nodoarbol(std::string auxnombre);
    std::string getNombre();
    nodoarbol *getHijoDerecho();
    nodoarbol *getHijoIzquierdo();
    void setNombre(std::string auxnombre);
    void setHijoDerecho(nodoarbol *auxhijoderecho);
    void setHijoIzquierdo(nodoarbol *auxhijoizquierdo);
};

#endif // NODOARBOL_H