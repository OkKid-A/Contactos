//
// Created by okkid-a on 3/26/24.
//

#ifndef CONTACTOS_MENU_H
#define CONTACTOS_MENU_H


#include "TablaHash.h"
#include "Grupo.h"

class Menu {
public:
    TablaHash<Grupo> *grupos;

    Menu();

    void imprimirMenuPrincipal();

    void imprimirMenuCrud();

    void imprimirMenuExportacion();

    void imprimirMenuGraficas();

    void imprimirMenuReportes();

    void imprimirGruposActivos() const;
};


#endif //CONTACTOS_MENU_H
