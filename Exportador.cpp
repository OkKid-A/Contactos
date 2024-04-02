//
// Created by okkid-a on 3/28/24.
//

#include "Exportador.h"


Exportador::Exportador() {}

void Exportador::exportarGrupo(TablaHash<Arbol> *tablaHash, string nombreGrupo) {
    string folder = "../" + nombreGrupo;
    if (fs::exists(folder) && fs::is_directory(folder)){
        cout << "Accesando a la carpeta del grupo."<<endl;
    } else {
        #ifdef _WIN32
            int creado = mkdir(folder.c_str());
        #else
            int creado = mkdir(folder.c_str(),0777);    
        #endif

        if (creado == 0){
            cout << "Se creo la carpeta del grupo."<<endl;
        } else {
            cout << "Error al crear la carpeta del grupo" << endl;
        }
    }
    Arbol *arbol = nullptr;
    int cont = 0;
    while (arbol == nullptr){
        arbol = tablaHash->getTablaElement(cont);
        cont++;
    }
    NodoArbol *raiz = arbol->raiz;
    printContact(raiz,folder,tablaHash->size);
    cout << "Se exporto el grupo correctamente." << endl;
}

void Exportador::printContact(NodoArbol *nodoArbol, string grupo, int size){
    if (nodoArbol->der == nullptr){
        if (nodoArbol->izq == nullptr){
            crearContacto(nodoArbol,grupo,size);
        }
    } else {
        printContact(nodoArbol->der,grupo,size);
        if (nodoArbol->izq != nullptr){
            printContact(nodoArbol->izq,grupo,size);
        }
        crearContacto(nodoArbol,grupo,size);
    }
}

void Exportador::crearContacto(NodoArbol *content, string folder, int size){
    string filepath = folder+"/"+content->key+".txt";
    string contenido = content->key;
    NodoArbol *temp = content;
    for (int i = 0; i < size-1; ++i) {
        temp = temp->siguiente;
        contenido += " " + temp->key;
    }
    ofstream outputFile(filepath);
    if (outputFile.is_open()){
        outputFile << contenido << endl;
        outputFile.close();
    } else {
        cout << "No se pudo crear el archivo para el contacto:" << content->key << endl;
    }
}
