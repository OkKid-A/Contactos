//
// Created by okkid-a on 3/26/24.
//
#include <iostream>
#include <string>
#include "Menu.h"
#include "Consola.h"
#include "Exportador.h"
#include "Graficador.h"
#include "Reportes.h"

using namespace std;

Menu::Menu() {
    this->grupos = new TablaHash<Grupo>();
}

void Menu::imprimirMenuPrincipal() {
    int respuesta;
    cout << endl << "1. Creacion, Insercion y Busqueda de Contactos." << endl << "2.Exportacion de Contactos." << endl
    << "3.Graficas" << endl << "4.Reportes" << endl;
    cin >> respuesta;
    switch (respuesta) {
        case 1:
            imprimirMenuCrud();
            break;
        case 2:
            imprimirMenuExportacion();
            break;
        case 3:
            imprimirMenuGraficas();
            break;
        case 4:
            imprimirMenuReportes();
            break;
        default:
            cout << "Ingreso no valido." << endl;
    }
}

void Menu::imprimirMenuCrud(){
    std::string resp;
    std::cout << "Insertar Comando:" << std::endl;
    cin >> ws;
    std::getline(std::cin,resp);
    auto *consola = new Consola();
    consola->analizarComando(resp, grupos);
    delete consola;
}

void Menu::imprimirMenuExportacion() {
    string grupoNombre;
    cout << "Ingresa el nombre del grupo que deseas exportar: " << endl;
    imprimirGruposActivos();
    getline(cin,grupoNombre);
    cin >> grupoNombre;
    auto *exportador = new Exportador();
    exportador->exportarGrupo(grupos->buscar(&grupoNombre)->hashMap,grupoNombre);
    delete exportador;
}

void Menu::imprimirMenuGraficas() {
    int respuesta;
    cout <<"1. Estado actual de toda la estructura." << endl << "2. Estado de un solo grupo." << endl <<
    "3. Estado (con datos) de un solo grupo." << endl;
    cin >> respuesta;
    auto *graficador = new Graficador();
    string grupoNombre;
    switch (respuesta) {
        case 1:
            graficador->graficarAll(this->grupos);
            break;
        case 2:
            cout << "Ingresa el nombre del grupo que deseas graficar: " << endl;
            imprimirGruposActivos();
            cin >> ws;
            getline(cin,grupoNombre);
            graficador->graficarGrupo(grupos->buscar(&grupoNombre), false, grupoNombre);
            break;
        case 3:
            cout << "Ingresa el nombre del grupo que deseas graficar: " << endl;
            imprimirGruposActivos();
            cin >> ws;
            getline(cin,grupoNombre);
            graficador->graficarGrupo(grupos->buscar(&grupoNombre), true, grupoNombre);
            break;
        default:
            cout << "Ingreso no valido." << endl;
    }
}

void Menu::imprimirMenuReportes() {
    int respuesta;
    cout << "1. Cantidad de datos por Grupo." << endl << "2. Cantidad de datos de todo el sistema." << endl <<
    "3. Cantidad de Contactos con el mismo tipo de dato del campo de criterio de ordenamiento." << endl <<
    "4. Cantidad de Contactos por Grupo." << endl;
    cin >> respuesta;
    string grupoNombre;
    Reportes * reportes = new Reportes();
    Grupo *grupo;
    string campo;
    switch (respuesta) {
        case 1:
            cout << "Ingresa el nombre del grupo: " << endl;
            imprimirGruposActivos();
            getline(cin,grupoNombre);
            reportes->cantidadGrupo(grupos,&grupoNombre);
            break;
        case 2:
            reportes->cantidadTotal(grupos);
            break;
        case 3:
            cout << "Ingresa el nombre del grupo: " << endl;
            imprimirGruposActivos();
            getline(cin,grupoNombre);
            reportes->cantidadContactosGrupo(grupos,&grupoNombre);
            break;
        case 4:
            cout << "Ingresa el nombre del grupo: " << endl;
            imprimirGruposActivos();
            getline(cin,grupoNombre);
            cout << "Ingresa el nombre del campo " << endl;
            grupo = grupos->buscar(&grupoNombre);
            for (int i = 0; i < grupo->hashMap->maxSize; ++i) {
                if (grupo->hashMap->tabla[i]!= nullptr){
                    cout << grupo->hashMap->key[i] << endl;
                }
            }
            cout << endl; cin >> campo;
            reportes->cantidadRepetida(grupos,&grupoNombre,&campo);
            break;
        default:
            cout << "Ingreso no valido." << endl;
    }
}

void Menu::imprimirGruposActivos() const{
    for (int i = 0; i < grupos->maxSize; ++i) {
        if (grupos->tabla[i]!= nullptr){
            cout << *grupos->key[i] << endl;
        }
    }
    cout<<endl;
}
