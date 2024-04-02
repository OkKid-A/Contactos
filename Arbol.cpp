//
// Created by okkid-a on 3/23/24.
//

#include "Arbol.h"

Arbol::Arbol() {raiz = nullptr;}

Arbol::Arbol(NodoArbol *raiz) : raiz(raiz) {}

NodoArbol *Arbol::insert(NodoArbol* nodo) {
            if (raiz == nullptr){
                raiz = nodo;
            } else {
                raiz->insert(nodo);
                balancearRaiz();
            }
            size++;
        return nodo;
}

void Arbol::balancearRaiz() {
    if (raiz->checkBalance() < -1){
        switch (raiz->der->checkBalance()) {
            case -1:
                raiz = raiz->rotarIzquierda(raiz);
                break;
            case 1:
                raiz = raiz->rotarDerechaIzquierda(raiz);
        }
    } else if (raiz->checkBalance() > 1) {
        switch (raiz->izq->checkBalance()) {
            case -1:
                raiz = raiz->rotarIzquierdaDerecha(raiz);
                break;
            case 1:
                raiz = raiz->rotarDerecha(raiz);
        }
    }
}

void Arbol::link(list<NodoArbol*> nodoList) {
    NodoArbol* temp = nullptr;
    for (auto rit = nodoList.rbegin(); rit != nodoList.rend(); rit++){
        NodoArbol* ref = *rit;
        ref->siguiente = temp;
        temp = *rit;
    }
    nodoList.back()->siguiente = nodoList.front();
}

int Arbol::repetidosNodo(NodoArbol *nodo){
    int repetidos = restarFrecuencia(nodo);
    if (nodo->izq != nullptr){
        repetidos += repetidosNodo(nodo->izq);
    }
    if (nodo->der != nullptr){
        repetidos += repetidosNodo(nodo->der);
    }
    return repetidos;
}

int Arbol::restarFrecuencia(NodoArbol *nodo){
    if (nodo->frecuencia > 1){
        return nodo->frecuencia-1;
    } else {
        return 0;
    }
}

string Arbol::dibujarArbol(bool valorKey) {
    string arbolDibujado;
    arbolDibujado+=dibujarNodo(raiz,valorKey);
    arbolDibujado+="\n";
    if (!dibujarLinks(raiz,valorKey).empty()){
        arbolDibujado+= dibujarLinks(raiz,valorKey);
    }
    return arbolDibujado;
}

string Arbol::dibujarNodo(NodoArbol *nodo, bool valorKey) {
    string nodos = addNodo(nodo, valorKey);
    if (nodo->izq!= nullptr){
        nodos+= dibujarNodo(nodo->izq, valorKey);
    }
    if (nodo->der!= nullptr){
        nodos+=dibujarNodo(nodo->der, valorKey);
    }
    return nodos;
}

string Arbol::addNodo(NodoArbol *nodo, bool valorKey){
    if (valorKey){
        return nodo->key + "[label=\"" + nodo->key + "\"];";
    } else {
        return to_string(nodo->keyValue) + "[label=\"" + to_string(nodo->keyValue) + "\"];";
    }
}

string Arbol::dibujarLinks(NodoArbol *nodo, bool valorKey) {
    string links;
    if (nodo->der == nullptr){
        if (nodo->izq == nullptr){
            return "";
        }
    } else {
        if (nodo->izq!= nullptr){
            links = addLink(nodo,valorKey,nodo->izq);
            links += dibujarLinks(nodo->izq,valorKey);
        }
        links += addLink(nodo,valorKey,nodo->der);
        links += dibujarLinks(nodo->der, valorKey);
    }
    return links;
}

string Arbol::addLink(NodoArbol *nodo, bool valorKey, NodoArbol *branch){
    if (valorKey){
        return  "   " + nodo->key + " -> " + branch->key + ";\n";
    } else {
        return "   " + to_string(nodo->keyValue) + " -> " + to_string(branch->keyValue) + ";\n";
    }
}







