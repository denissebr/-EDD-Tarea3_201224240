#include "arbol.h"

arbol::arbol(){
    raiz = NULL;
}

void arbol::Insertar_arbol(nodoarbol *nuevo){
    nodoarbol *padre = NULL;
    nodoarbol *actual = raiz;
    if(!Existe_n(nuevo->getNombre(), raiz)){
        while (actual != NULL)
        {
            /* code */
            padre = actual;
            if(strcmp(actual->getNombre().c_str(), nuevo->getNombre().c_str()) > 0){
               actual = actual->getHijoIzquierdo();
            }else if(strcmp(actual->getNombre().c_str(), nuevo->getNombre().c_str()) < 0){
                actual = actual->getHijoDerecho();
            }
        }
        if(padre == NULL){
            raiz = nuevo;
        }else if(strcmp(padre->getNombre().c_str(), nuevo->getNombre().c_str()) > 0){
            padre->setHijoIzquierdo(nuevo);
        }else{
            padre->setHijoDerecho(nuevo);
        }
    }
}

nodoarbol *arbol::getRaiz(){
    return raiz;
}


bool arbol::Existe_n(std::string nombre, nodoarbol *auxraiz){
    if(auxraiz == 0){
        return false;
    }else{
        if(strcmp(auxraiz->getNombre().c_str(), nombre.c_str()) > 0){
            return Existe_n(nombre, auxraiz->getHijoIzquierdo());
        }else if(strcmp(auxraiz->getNombre().c_str(), nombre.c_str()) < 0){
            return Existe_n(nombre, auxraiz->getHijoDerecho());
        }
        else{
            return true;
        }
    }
}