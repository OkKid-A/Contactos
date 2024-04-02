//
// Created by okkid-a on 3/23/24.
//

#ifndef CONTACTOS_NODOARBOL_H
#define CONTACTOS_NODOARBOL_H

#include <string>

using namespace std;

class NodoArbol {

private:
public:
    string type;
    bool raiz;
    string key;
    int keyValue;
    int altura;
    int frecuencia;
    NodoArbol *siguiente;
    NodoArbol *izq;
    NodoArbol *der;

    NodoArbol(string *type, string key, int keyValue);
    int insert(string tipo, const string& key, int valueKey);
    NodoArbol* rotarDerecha(NodoArbol*);
    NodoArbol* rotarIzquierda(NodoArbol*);
    NodoArbol* rotarIzquierdaDerecha(NodoArbol* prevTop);
    NodoArbol* rotarDerechaIzquierda(NodoArbol* prevTop);
    void balanceBranch(NodoArbol* parent);
    void balancear();
    int checkBalance();
    static int getAltura(NodoArbol*);
    NodoArbol *attachSon(NodoArbol *parent, NodoArbol *son, bool isDer);
    void balancear(NodoArbol *parent, NodoArbol *branch, bool isDer);
    int insert(NodoArbol *nodoArbol);

    NodoArbol *buscar(int keyV, string llave);
};


#endif //CONTACTOS_NODOARBOL_H
