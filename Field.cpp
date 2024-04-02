//
// Created by okkid-a on 3/26/24.
//

#include "Field.h"

#include <utility>

Field::Field(string *nombre, Field::Tipo tipoDato) : nombre(nombre), tipoDato(tipoDato) {}

Field::Tipo Field::castTipo(char *valor) {
    string value = valor;
    if (value == "STRING"){
        return Tipo::STRING;
    } else if (value == "INTEGER") {
        return Tipo::INTEGER;
    } else if (value == "DATE"){
        return Tipo::DATE;
    } else {
        return Tipo::CHAR;
    }
}

string Field::retornarNombre(){
    string find = *this->nombre;
    return find;
}


