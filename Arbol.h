//
// Created by okkid-a on 3/23/24.
//

#ifndef CONTACTOS_ARBOL_H
#define CONTACTOS_ARBOL_H


#include <list>
#include "NodoArbol.h"
#include "TablaHash.h"


class Arbol {
private:
public:
    NodoArbol* raiz;
    int size;

    Arbol();
    explicit Arbol(NodoArbol *raiz);
    void link(list<NodoArbol*> nodoList);
    void balancearRaiz();
    NodoArbol *insert(NodoArbol *nodo);
    string dibujarLinks(NodoArbol* nodo, bool valorKey);
    string dibujarArbol(bool valorKey);
    string dibujarNodo(NodoArbol *nodo, bool valorKey);
    string addNodo(NodoArbol *nodo, bool valorKey);
    string addLink(NodoArbol *nodo, bool valorKey, NodoArbol *branch);

    int contarRepetidos();

    int repetidosNodo(NodoArbol *nodo);

    int restarFrecuencia(NodoArbol *nodo);
};


#endif //CONTACTOS_ARBOL_H
