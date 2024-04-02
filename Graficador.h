//
// Created by okkid-a on 3/27/24.
//

#ifndef CONTACTOS_GRAFICADOR_H
#define CONTACTOS_GRAFICADOR_H


#include "Arbol.h"
#include "Grupo.h"

class Graficador {
public:
    void graficarArbol(Arbol *arbol);
    void crearGrafico(string content, string graphName);

    string graficarHashMap(TablaHash<Arbol> *grupo, string* parName);

    void graficarAll(TablaHash<Grupo> *hash);

    void graficarGrupo(Grupo *arbol, bool porClave, string graphName);
};


#endif //CONTACTOS_GRAFICADOR_H
