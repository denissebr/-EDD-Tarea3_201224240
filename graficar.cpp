#include "graficar.h"

graficar::graficar(arbol *arbol_n){
    grafica = fopen("./Arbol.dot", "w+");
    fprintf(grafica, "digraph{\n");
    fprintf(grafica, "subgraph clusterArbol{\n");
    fprintf(grafica, "node[shape=record]\n");
    graficar_nodos_arbol(arbol_n->getRaiz(), "r");
    relacionar_nodos_arbol(arbol_n->getRaiz(), "r");
    fprintf(grafica, "}\n");
    fprintf(grafica, "}");
    fclose(grafica);
    system("dot -Tjpg ./Arbol.dot -o ./Arbol.jpg");
}

void graficar::graficar_nodos_arbol(nodoarbol *arbol, std::string id){
    if(arbol != NULL){
        fprintf(grafica, "a%s[label=\"<f0>|<f1>%s|<f2>\"];\n", id.c_str(), arbol->getNombre().c_str());
        if(arbol->getHijoIzquierdo() != NULL){
            std::string auxid = id + "I";
            graficar_nodos_arbol(arbol->getHijoIzquierdo(), auxid);
        }
        if(arbol->getHijoDerecho() != NULL){
            std::string auxid = id + "D";
            graficar_nodos_arbol(arbol->getHijoDerecho(), auxid);
        }
    }
}

void graficar::relacionar_nodos_arbol(nodoarbol *arbol, std::string id){
    if(arbol != NULL){
        if(arbol->getHijoDerecho() != NULL){
            fprintf(grafica, "a%s:<f2>->a%sD:<f1>;\n", id.c_str(), id.c_str());
        }
        if(arbol->getHijoIzquierdo() != NULL){
            fprintf(grafica, "a%s:<f0>->a%sI:<f1>;\n", id.c_str(), id.c_str());
        }
        if(arbol->getHijoIzquierdo() != NULL){
            std::string auxid = id + "I";
            relacionar_nodos_arbol(arbol->getHijoIzquierdo(), auxid);
        }
        if(arbol->getHijoDerecho() != NULL){
            std::string auxid = id + "D";
            relacionar_nodos_arbol(arbol->getHijoDerecho(), auxid);
        }
    }
}