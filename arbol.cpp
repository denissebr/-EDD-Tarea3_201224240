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

void arbol::Eliminar(std::string nombre){
    nodoarbol *padre = NULL;
    nodoarbol *actual = raiz;
    if(Existe_n(nombre, raiz)){
        while (actual && strcmp(actual->getNombre().c_str(), nombre.c_str()) != 0)
        {
            padre = actual;
            if(strcmp(actual->getNombre().c_str(), nombre.c_str()) > 0){
                actual = actual->getHijoIzquierdo();
            }else{
                actual = actual->getHijoDerecho();
            }
        }

        if(actual->getHijoDerecho() == NULL && actual->getHijoIzquierdo() == NULL){
            if(padre != NULL){
                if(padre->getHijoDerecho() == actual){
                    padre->setHijoDerecho(NULL);
                }else
                {
                    padre->setHijoIzquierdo(NULL);
                }
            }else{
                raiz = NULL;
            }
        }else if(actual->getHijoDerecho() == NULL || actual->getHijoIzquierdo() == NULL){
            if(padre != NULL){
                if(padre->getHijoDerecho() == actual){
                    if(actual->getHijoDerecho() != NULL){
                        padre->setHijoDerecho(actual->getHijoDerecho());
                        actual->setHijoDerecho(NULL);
                    }else if(actual->getHijoIzquierdo() != NULL){
                        padre->setHijoIzquierdo(actual->getHijoIzquierdo());
                        actual->setHijoIzquierdo(NULL);
                    }
                }else if(padre->getHijoIzquierdo() == actual){
                    if(actual->getHijoDerecho() != NULL){
                        padre->setHijoDerecho(actual->getHijoDerecho());
                        actual->setHijoDerecho(NULL);
                    }else if(actual->getHijoIzquierdo() != NULL){
                        padre->setHijoIzquierdo(actual->getHijoIzquierdo());
                        actual->setHijoIzquierdo(NULL);
                    }
                }
                actual = NULL;
            }else{
                if(actual->getHijoDerecho() != NULL){
                    raiz = actual->getHijoDerecho();
                }else if(actual->getHijoIzquierdo() != NULL){
                    raiz = actual->getHijoIzquierdo();
                }
                actual = NULL;
            }
        }else{
            nodoarbol *aux = actual->getHijoDerecho();
            nodoarbol *padreaux = NULL;
            while(aux->getHijoIzquierdo() != NULL)
            {
                padreaux = aux;
                aux = aux->getHijoIzquierdo();
            }
            if(aux->getHijoDerecho() != NULL && padreaux != NULL)
            {
                padreaux->setHijoIzquierdo(aux->getHijoDerecho());
            }
            else if(padreaux != NULL)
            {
                padreaux->setHijoIzquierdo(NULL);
            }
            if(padre != NULL)
            {
                if(padre->getHijoIzquierdo() == actual)
                {
                    if(actual->getHijoDerecho() != aux)
                    {
                        aux->setHijoDerecho(actual->getHijoDerecho());
                    }
                    aux->setHijoIzquierdo(actual->getHijoIzquierdo());
                    padre->setHijoIzquierdo(aux);
                    actual->setHijoDerecho(NULL);
                }
                else if(padre->getHijoDerecho() == actual)
                {
                    aux->setHijoIzquierdo(actual->getHijoIzquierdo());
                    if(actual->getHijoDerecho() != aux)
                    {
                        aux->setHijoDerecho(actual->getHijoDerecho());
                    }
                    padre->setHijoDerecho(aux);
                    actual->setHijoDerecho(NULL);
                }
                actual = NULL;
            }
            else
            {
                if(actual->getHijoDerecho() == aux)
                {
                    aux->setHijoIzquierdo(actual->getHijoIzquierdo());
                    actual->setHijoDerecho(NULL);
                    raiz = aux;
                }
                else
                {
                    aux->setHijoDerecho(actual->getHijoDerecho());
                    aux->setHijoIzquierdo(actual->getHijoIzquierdo());
                    raiz = aux;
                }
                aux = NULL;
            }
            
        }
        
    } 
}