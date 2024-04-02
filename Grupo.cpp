//
// Created by okkid-a on 3/26/24.
//

#include <iostream>
#include <chrono>
#include "Grupo.h"


Grupo::Grupo(list<Field*> *fields) {
    this->fields = fields;
    this->hashMap =  new TablaHash<Arbol>();
    for (Field *field: *this->fields) {
        hashMap->insert(new Arbol(), field->nombre);
    }
}

void Grupo::insertContacto(list<string>* datos) {
    if (datos->size()==hashMap->size){
        int cont = 0;
        list<NodoArbol*> nodos;
        NodoArbol *temp;
        for (string dato: *datos) {
            auto it = this->fields->begin();
            advance(it,cont);
            Field *field = *it;
            Arbol* found = hashMap->buscar(field->nombre);
            temp = new NodoArbol(field->nombre, dato, traducirDato(field->tipoDato,dato));
            nodos.emplace_back(temp);
            found->insert(temp);
            cont++;
        }
        auto it = this->fields->begin();
        advance(it,0);
        Field *field = *it;
        Arbol* found = hashMap->buscar(field->nombre);
        found->link(nodos);
    } else {
        cout << endl << "El contacto no contiene suficientes campos."<< endl;
    }
}

int transASCIIValue(const string& valor){
    int total = 0;
    for (char c: valor) {
        int ascii = static_cast<int> (c);
        total += ascii;
    }
    return total;
}

 int transDateValue(const char *valor){
    struct tm tm{};
    strptime(valor,"%d-%m-%Y",&tm);
    time_t timeSeconds = mktime(&tm);
    chrono::system_clock::time_point parsedTime = chrono::system_clock::from_time_t(timeSeconds);
    return parsedTime.time_since_epoch().count();
}

int Grupo::traducirDato(Field::Tipo tipo, string valor) {
    switch (tipo) {
        case Field::Tipo::STRING:
            return transASCIIValue(valor);
        case Field::Tipo::DATE:
            return transDateValue(valor.c_str());
        case Field::Tipo::INTEGER:
            return stoi(valor);
        case Field::Tipo::CHAR:
            return static_cast<int> (valor[0]);
        default:
            return 0;
    }
}

Field* Grupo::encontrarField(string *nombre){
    for (Field* field: *this->fields) {
        if (*field->nombre == *nombre){
            return field;
        }
    }
}






