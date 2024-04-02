//
// Created by okkid-a on 3/27/24.
//

#ifndef CONTACTOS_DATO_H
#define CONTACTOS_DATO_H

#include <string>

using namespace std;

class Dato {
public:
    string *campo;
    string valor;

    Dato(string *campo, const string &valor);
};


#endif //CONTACTOS_DATO_H
