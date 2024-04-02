//
// Created by okkid-a on 3/26/24.
//

#ifndef CONTACTOS_CONSOLA_H
#define CONTACTOS_CONSOLA_H

#include <string>
#include <list>
#include "Field.h"
#include "Dato.h"
#include "TablaHash.h"
#include "Grupo.h"

using namespace std;

class Consola {
public:
    string* findNombre(string createCom);
    string* findNombreGrupo(const string& contCom);
    Dato* findDato(string busCom);
    list<Field*>* recuperarCampos(string createCom);
    list<string>* datos(const string& contCom);
    Field *formarField(char *campo);
    void analizarComando(const string& comando, TablaHash<Grupo> *grupos);

    string *crearCopia(string arreglo);

    string *crearCopia(char *arreglo);

    char *crearCopiaChar(char *arreglo);
};


#endif //CONTACTOS_CONSOLA_H
