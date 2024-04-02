//
// Created by okkid-a on 3/21/24.
//

#ifndef CONTACTOS_TABLAHASH_H
#define CONTACTOS_TABLAHASH_H

#include <iostream>
#include "string"
#include "cmath"

using namespace std;

template <typename T>
class TablaHash {
private:
public:

    T **tabla;
    string **key;
    float size;
    int maxSize;


    TablaHash();

    int hash(int);
    int hashString(string*);
    void resize(int nextPrimo);
    int nextSize();
    T *buscar(string *key);
    T *getTabla() const;
    string * getElementName(int index);
    T *getTablaElement(int index) const;
    void insert(T *valor, string *name);
    int esPrimo(int n);
};

template<typename T>
int TablaHash<T>::esPrimo(int n){
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}


template<typename T>
int TablaHash<T>::nextSize() {
    int prime = maxSize;
    bool found = false;
    while (!found) {
        prime++;
        if (esPrimo(prime))
            found = true;
    }
    return prime;
}

template<typename T>
int TablaHash<T>::hashString(string *name) {
    int valorAscii = 0;
    for (char c: *name) {
        valorAscii += c - 'a' + 1;
    }
    int hashValue = valorAscii % maxSize;
    return hashValue;
}

template<typename T>
TablaHash<T>::TablaHash() {
    this->maxSize = 5;
    this->tabla = new T*[maxSize];
    this->key = new string *[maxSize];
    this->size = 0;
    for (int i = 0; i < maxSize; ++i) {
        this->tabla[i] = nullptr;
        this->key[i] = nullptr;
    }
}

template<typename T>
void TablaHash<T>::resize(int nextPrimo) {
    T **nextArray = new T*[nextPrimo];
    auto **nextKeys = new string *[nextPrimo];
    int oldSize = maxSize;
    for (int i = 0; i < nextPrimo; ++i) {
        nextArray[i] = nullptr;
        nextKeys[i] = nullptr;
    }
    this->maxSize = nextPrimo;
    for (int i = 0; i < oldSize; ++i) {
        if (this->tabla[i]!= nullptr){
            int hashValue = hashString(this->key[i]);
            while (true){
                if (nextArray[hashValue] == nullptr){
                    nextArray[hashValue] = this->tabla[i];
                    auto *next = new string (*this->key[i]);
                    nextKeys[hashValue] = next;
                    break;
                } else {
                    if (hashValue>=maxSize-1){
                        hashValue++;
                    } else {
                        hashValue = 0;
                    }
                }
            }
        }
    }
    delete[] tabla;
    delete[] key;
    this->tabla = nextArray;
    this->key = nextKeys;
}

template<typename T>
void TablaHash<T>::insert(T *valor, string *name) {
    int index;
    if (size>0) {
        float factor = size / maxSize;
        if ((factor) > 0.6) {
            resize(nextSize());
        }
    }
    index = hashString(name);
    while (true){
        if (tabla[index]!= nullptr){
            if (index>=maxSize-1){
                index = 0;
            } else{
                index++;
            }
        } else {
            tabla[index] = valor;
            auto *newKey = new string(*name);
            key[index] = newKey;
            break;
        }
    }
    size++;
}

template<typename T>
T* TablaHash<T>::buscar(string *keyS) {
    int keyValue= hashString(keyS);
    while (true) {
        if (this->key[keyValue] != nullptr) {
            if (*this->key[keyValue] == *keyS) {
                return tabla[keyValue];
            } else {
                if (keyValue>=maxSize-1){
                    keyValue = 0;
                } else {
                    keyValue++;
                }
            }
        } else {
            if (keyValue>=maxSize-1){
                keyValue = 0;
            } else {
                keyValue++;
            }
        }
    }
}

template<typename T>
int TablaHash<T>::hash(int valor) {
    return valor % maxSize;
}





template<typename T>
T* TablaHash<T>::getTabla() const {
    return tabla;
}

template<typename T>
T* TablaHash<T>::getTablaElement(int index) const {
    return tabla[index];
}

template<typename T>
string * TablaHash<T>::getElementName(int index) {
    return key[index];
}

#endif //CONTACTOS_TABLAHASH_H
