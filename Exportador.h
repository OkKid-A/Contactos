//
// Created by okkid-a on 3/28/24.
//

#ifndef CONTACTOS_EXPORTADOR_H
#define CONTACTOS_EXPORTADOR_H


#include "TablaHash.h"
#include "Arbol.h"
#include <iostream>
#include<string>
#include <fstream>
#include <filesystem>

#ifdef _WIN32
#include <direct.h>
    #define mkdir _mkdir
#else
#include <sys/stat.h>
#endif

using namespace std;
namespace fs = std::filesystem;

class Exportador {
public:
    Exportador();
    static void crearContacto(NodoArbol *content, string folder, int size);
    void printContact(NodoArbol *nodoArbol, string grupo, int size);
    void exportarGrupo(TablaHash<Arbol> *tablaHash, string nombreGrupo);
};


#endif //CONTACTOS_EXPORTADOR_H
