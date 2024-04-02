//
// Created by okkid-a on 3/26/24.
//

#ifndef CONTACTOS_GRUPO_H
#define CONTACTOS_GRUPO_H


#include "Arbol.h"
#include "Field.h"
#include "TablaHash.h"


using namespace std;

class Grupo {
public:


    TablaHash<Arbol> *hashMap;
    list<Field*> *fields;

    explicit Grupo(list <Field*> *fields);

    void insertContacto(list<string> *datos);
    int traducirDato(Field::Tipo tipo, string valor);
    Field *encontrarField(string *nombre);
    Field *regresarFieldNombre(int index);
};


#endif //CONTACTOS_GRUPO_H
