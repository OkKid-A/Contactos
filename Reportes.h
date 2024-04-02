//
// Created by okkid-a on 4/1/24.
//

#ifndef CONTACTOS_REPORTES_H
#define CONTACTOS_REPORTES_H

#include <string>
#include "TablaHash.h"
#include "Arbol.h"
#include "Grupo.h"

using namespace std;

class Reportes {
public:


    void cantidadTotal(TablaHash<Grupo> *hash);

    int cantidadContactosGrupo(TablaHash<Grupo> *hash, string *grupo);

    void cantidadRepetida(TablaHash<Grupo> *hash, string *grupo,  string *campo);

    int cantidadGrupo(TablaHash<Grupo> *hash, string *grupo);
};


#endif //CONTACTOS_REPORTES_H
