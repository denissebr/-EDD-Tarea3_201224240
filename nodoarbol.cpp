#include "nodoarbol.h"

nodoarbol::nodoarbol(std::string auxnombre){
    nombre = auxnombre;
    hijoderecho = NULL;
    hijoizquierdo = NULL;
}

std::string nodoarbol::getNombre(){
    return nombre;
}

nodoarbol *nodoarbol::getHijoDerecho(){
    return hijoderecho;
}

nodoarbol *nodoarbol::getHijoIzquierdo(){
    return hijoizquierdo;
}

void nodoarbol::setNombre(std::string auxnombre){
    nombre = auxnombre;
}

void nodoarbol::setHijoDerecho(nodoarbol *auxhijoderecho){
    hijoderecho = auxhijoderecho;
}

void nodoarbol::setHijoIzquierdo(nodoarbol *auxhijoizquierdo){
    hijoizquierdo = auxhijoizquierdo;
}