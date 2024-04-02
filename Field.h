//
// Created by okkid-a on 3/26/24.
//

#ifndef CONTACTOS_FIELD_H
#define CONTACTOS_FIELD_H

#include <string>

using namespace std;

class Field {
public:
    string *nombre;
    enum Tipo {STRING, CHAR, INTEGER, DATE};
    Tipo tipoDato;

    Field(string *nombre, Tipo tipoDato);
    static Tipo castTipo(char *);

    string retornarNombre();
};


#endif //CONTACTOS_FIELD_H
