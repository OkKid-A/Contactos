//
// Created by okkid-a on 3/23/24.
//

#include "NodoArbol.h"

#include <utility>

using namespace std;

NodoArbol::NodoArbol(string *type, string key, int keyValue) : type(*type), key(key), keyValue(keyValue) {
    this->altura = 0;
    this->frecuencia = 1;
    this->izq = nullptr;
    this->der = nullptr;
}

int NodoArbol::insert(NodoArbol* nodoArbol) {
    int nuevaAltura;
    if (nodoArbol->keyValue < this->keyValue){
        if (izq== nullptr){
            this->izq = nodoArbol;
            if (this->der == nullptr){
                altura++;
            }
            nuevaAltura = 0;
        } else {
            this->altura = izq->insert(nodoArbol);
            nuevaAltura =  altura+1;
        }
    } else if (nodoArbol->keyValue > this->keyValue){
        if (der== nullptr){
            this->der = nodoArbol;
            if (this->izq == nullptr){
                altura++;
            }
            nuevaAltura = 0;
        } else {
            this->altura = der->insert(nodoArbol);
            nuevaAltura = altura+1;
        }
    } else {
        nodoArbol->frecuencia++;
        if (der== nullptr){
            this->der = nodoArbol;
            if (this->izq == nullptr){
                altura++;
            }
            nuevaAltura = 0;
        } else {
            this->altura = der->insert(nodoArbol);
            nuevaAltura = altura+1;
        }
    }
    balanceBranch(this);
    return nuevaAltura;
}

NodoArbol* NodoArbol::buscar(int keyV, string llave){
    if (this->keyValue == keyV){
        if (this->key == llave){
            return this;
        } else {
            if (this->der != nullptr) {
                return this->der->buscar(keyV, llave);
            } else {
                return nullptr;
            }
        }
    } else if (this->keyValue < keyV){
        if (this->der == nullptr){
            return nullptr;
        } else {
            return this->der->buscar(keyV,llave);
        }
    } else if (this->keyValue > keyV){
        if (this->izq == nullptr){
            return nullptr;
        } else {
            return this->izq->buscar(keyV, llave);
        }
    }
}

void balanceAlturas(NodoArbol* act){
    act->altura = 1 + max(act->getAltura(act->izq),act->getAltura(act->der));
}

void NodoArbol::balanceBranch(NodoArbol *parent) {
    if (parent->izq!= nullptr){
        balancear(parent,parent->izq, false);
    }
    if (parent->der!= nullptr){
        balancear(parent,parent->der, true);
    }
}

void NodoArbol::balancear(NodoArbol* parent, NodoArbol* branch, bool isDer) {
    if (branch->checkBalance() < -1){
            switch (branch->der->checkBalance()) {
                case -1:
                    attachSon(parent, rotarIzquierda(branch), isDer);
                    break;
                case 1:
                    attachSon(parent, rotarDerechaIzquierda(branch), isDer);
            }
    } else if (branch->checkBalance() > 1) {
        switch (branch->izq->checkBalance()) {
            case -1:
                attachSon(parent, rotarIzquierdaDerecha(branch),isDer);
                break;
            case 1:
                attachSon(parent, rotarDerecha(branch),isDer);
        }
    }
}

int NodoArbol::checkBalance() {
    return getAltura(this->izq) - getAltura(this->der);
}

NodoArbol* NodoArbol::rotarDerecha(NodoArbol* prevTop) {
    NodoArbol* newTop = prevTop->izq;
    NodoArbol* tempNodo = newTop->der;
    newTop->der = prevTop;
    prevTop->izq = tempNodo;
    balanceAlturas(newTop);
    balanceAlturas(prevTop);
    return newTop;
}

NodoArbol* NodoArbol::rotarIzquierda(NodoArbol* prevTop) {
    NodoArbol* newTop = prevTop->der;
    NodoArbol* tempNodo = newTop->izq;
    newTop->izq = prevTop;
    prevTop->der = tempNodo;
    balanceAlturas(newTop);
    balanceAlturas(prevTop);
    return newTop;
}

NodoArbol* NodoArbol::rotarIzquierdaDerecha(NodoArbol *prevTop) {
    prevTop->izq = rotarIzquierda(prevTop->izq);
    NodoArbol* nuevoTop = rotarDerecha(prevTop);
    return nuevoTop;
}

NodoArbol *NodoArbol::rotarDerechaIzquierda(NodoArbol *prevTop) {
    prevTop->der = rotarDerecha(prevTop->der);
    NodoArbol* nuevoTop = rotarIzquierda(prevTop);
    return nuevoTop;
}

int NodoArbol::getAltura(NodoArbol* nodo)  {
    if (nodo == nullptr){
        return 0;
    } else {
        return nodo->altura;
    }
}

NodoArbol* NodoArbol::attachSon(NodoArbol* parent, NodoArbol* son, bool isDer){
    if (isDer){
        parent->der = son;
    } else {
        parent->izq = son;
    }
}





