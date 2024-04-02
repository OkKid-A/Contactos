//
// Created by okkid-a on 3/26/24.
//

#include <fstream>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

#include "Consola.h"

using namespace std;

void Consola::analizarComando(const string& comando, TablaHash<Grupo> *grupos){
    char * charString = new char [comando.size() + 1];
    strcpy(charString,comando.c_str());
    size_t length = strlen(charString);
    char *temp = new char[length+1];
    copy_n(charString,length,temp);
    temp[length] = '\0';
    string nombreCut = strtok(temp, " ");
    string tipo = strtok(nullptr," ");
    if (nombreCut == "ADD"){
        if (tipo == "NEW-GROUP"){
            Grupo *grupo = new Grupo(recuperarCampos(comando));
            grupos->insert(grupo, findNombre(comando));
        } else if (tipo == "CONTACT") {
            Grupo *grupoToAdd = grupos->buscar(findNombreGrupo(comando));
            grupoToAdd->insertContacto(datos(comando));
        } else {
            cout << endl << "Comando no reconocido.";
        }
    } else if (nombreCut == "FIND"){
        Grupo *grupoToFind = grupos->buscar(findNombreGrupo(comando));
        Dato *dato = findDato(comando);
        Arbol *campo = grupoToFind->hashMap->buscar(dato->campo);
        int keyV = grupoToFind->traducirDato(grupoToFind->encontrarField(dato->campo)->tipoDato, dato->valor);
        NodoArbol* nodo = campo->raiz->buscar(keyV,dato->valor);
        NodoArbol* tempNodo = nodo->siguiente;
        while (nodo!= nullptr){
            cout << "Contacto con campo "+ nodo->type + ": " + nodo->key<< endl;
            for (int i = 0; i < grupoToFind->hashMap->size -1; ++i) {
                cout << tempNodo->type + ": " + tempNodo->key << endl;
                tempNodo = tempNodo->siguiente;
            }
            if (campo->raiz->der!= nullptr) {
                nodo = campo->raiz->der->buscar(keyV, dato->valor);
            } else {
                nodo = nullptr;
            }
        }
    } else {
        cout << endl << "Comando no reconocido.";
    }
}

string* Consola::findNombre(string createCom) {
    const char * charString = createCom.c_str();
    size_t length = strlen(charString);
    char *temp = new char[length+1];
    copy_n(charString,length,temp);
    temp[length] = '\0';
    string nombreCut = strtok(temp, " ");
    char *nombreFinal = strtok(NULL," ");
    nombreFinal = strtok(nullptr," ");
    return crearCopia(nombreFinal);
}

list<Field*>* Consola::recuperarCampos(string createCom) {
    const char * charString = createCom.c_str();
    size_t length = strlen(charString);
    char *temp = new char[length+1];
    copy_n(charString,length,temp);
    temp[length] = '\0';
    string fieldcut = strtok(temp, "(");
    fieldcut = strtok(nullptr, "(");
    const char * fieldsString = fieldcut.c_str();
    size_t lengthFields = strlen(fieldsString);
    char *tempFields = new char[lengthFields+1];
    copy_n(fieldsString,lengthFields,tempFields);
    tempFields[lengthFields] = '\0';
    char* field = tempFields;
    auto *fields = new list<Field*>();
    field = strtok(field," ,);");
    while (field != NULL){
        Field *campo =formarField(crearCopiaChar(field));
        fields->push_back(campo);
        field = strtok(nullptr," ,);");
    }
    return fields;
}

Field * Consola::formarField(char* campo) {
    char *tipo = strtok(nullptr," ,);");
    string* copia = crearCopia(campo);
    return new Field(copia, Field::castTipo(tipo));
}

string* Consola::crearCopia(char* arreglo){
    int size = strlen(arreglo)+1;
    char *copiaChar = new char[size];
    strcpy(copiaChar,arreglo);
    std::string copia(copiaChar);
    string *puntero = new string(copia);
    delete[] copiaChar;
    return puntero;
};

char* Consola::crearCopiaChar(char* arreglo){
    string par = arreglo;
    char* copiaChar = new char[par.size()+1];
    strcpy(copiaChar,arreglo);
    return copiaChar;
}

string* Consola::findNombreGrupo(const string& contCom) {
    const char * charString = contCom.c_str();
    size_t length = strlen(charString);
    char *temp = new char[length+1];
    copy_n(charString,length,temp);
    temp[length] = '\0';
    char *nombreCut = strtok(temp, " ");
    nombreCut = strtok(NULL," ");
    nombreCut = strtok(NULL," ");
    nombreCut = strtok(NULL," ");
    return crearCopia(nombreCut);
}

list<string> *Consola::datos(const string& contCom) {
    const char * charString = contCom.c_str();
    size_t length = strlen(charString);
    char *temp = new char[length+1];
    copy_n(charString,length,temp);
    temp[length] = '\0';
    char *tempFields = strtok(temp, "(");
    char* field = strtok(nullptr," ,);");
    auto *datos = new list<string>;
    while (field != NULL){
        datos->emplace_back(field);
        field = strtok(NULL," ,);");
    }
    return datos;
}

Dato* Consola::findDato(string busCom) {
    const char * charString = busCom.c_str();
    size_t length = strlen(charString);
    char *temp = new char[length+1];
    copy_n(charString,length,temp);
    temp[length] = '\0';
    strtok(temp, "-");
    strtok(nullptr, " ;=");
    char *campo = strtok(nullptr," ;=");
    char *key = strtok(nullptr, " ;=");
    return new Dato(crearCopia(campo), key);
}







