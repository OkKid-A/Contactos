//
// Created by okkid-a on 4/1/24.
//

#include <iostream>
#include "Reportes.h"

int Reportes::cantidadGrupo(TablaHash<Grupo> *hash, string *grupo) {
    Grupo *grupoHash = hash->buscar(grupo);
    Arbol *arbol = grupoHash->hashMap->buscar(grupoHash->fields->front()->nombre);
    cout << *grupo + ": " + to_string(arbol->size * grupoHash->hashMap->size) << endl;
    return arbol->size * grupoHash->hashMap->size;
}

int Reportes::cantidadContactosGrupo(TablaHash<Grupo> *hash, string *grupo) {
    Grupo *grupoHash = hash->buscar(grupo);
    Arbol *arbol = grupoHash->hashMap->buscar(grupoHash->fields->front()->nombre);
    cout << "Contactos del " + *grupo + ": " + to_string(arbol->size) << endl;
    return arbol->size;
}

void Reportes::cantidadTotal(TablaHash<Grupo> *hash){
    cout << "Cantidad de datos totales:\n";
    int total = 0;
    for (int i = 0; i < hash->maxSize; ++i) {
        if (hash->getTablaElement(0)!= nullptr){
            total += cantidadGrupo(hash, hash->getElementName(0));
        }
    }
    cout << "Total: " + to_string(total) << endl;
}

void Reportes::cantidadRepetida(TablaHash<Grupo> *hash, string* grupo, string* campo){
    int repetidos;
    Grupo *grupoHash = hash->buscar(grupo);
    Arbol *arbol = grupoHash->hashMap->buscar(campo);
    cout << "Contactos con el mismo dato de ordenamiento " + *campo + " en el grupo " + *grupo + ": "
    + to_string(arbol->repetidosNodo(arbol->raiz)) << endl;
}
