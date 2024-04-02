//
// Created by okkid-a on 3/27/24.
//

#include <fstream>
#include <iostream>
#include <utility>
#include "Graficador.h"
#include "Grupo.h"

void Graficador::graficarGrupo(Grupo *arbol, bool porClave, string graphName) {
    string hashContent = "digraph G {\n   node [shape=circle, style=filled, fillcolor=lightblue, fontcolor=black]\n;";
    TablaHash<Arbol> *grupo = arbol->hashMap;
    for (int i = 0; i < grupo->maxSize; ++i) {
        Arbol *arbol = grupo->getTablaElement(i);
        if (arbol != nullptr){
            hashContent +=  *grupo->getElementName(i) +" [label=\""+ *grupo->getElementName(i)+"\"] [shape = \"rectangle\"];\n";
            hashContent += arbol->dibujarArbol(porClave);
            if (!porClave){
                hashContent += *grupo->getElementName(i) +" ->" + to_string(arbol->raiz->keyValue) + ";\n";
            } else {
                hashContent += *grupo->getElementName(i) +" ->" + (arbol->raiz->key) + ";\n";
            }
        }
    }
    hashContent += "}";
    crearGrafico(hashContent,graphName);
}

void Graficador::graficarAll(TablaHash<Grupo> *hash) {
    string grafo = "digraph G {\n   node [shape=circle, style=filled, fillcolor=lightblue, fontcolor=black];\n";
    grafo +=  "inicioDeContactos [label=\"Tabla Hash\"] [shape = \"square\"];\n";
    for (int i = 0; i < hash->maxSize; ++i) {
        Grupo * grupo = hash->getTablaElement(i);
        if (grupo != nullptr){
            grafo += "inicioDeContactos ->" + *hash->getElementName(i) + ";\n";
            grafo += graficarHashMap(grupo->hashMap, hash->getElementName(i));
        }
    }
    grafo += "}";
    crearGrafico(grafo,"sistema");
}

string Graficador::graficarHashMap(TablaHash<Arbol> *grupo, string* parName){
    string hashContent;
    for (int i = 0; i < grupo->maxSize; ++i) {
        Arbol *arbol = grupo->getTablaElement(i);
        if (arbol != nullptr){
            hashContent +=  *grupo->getElementName(i) +" [label=\""+ *grupo->getElementName(i)+"\"] [shape = \"rectangle\"];\n";
            hashContent += *parName+" ->"+*grupo->getElementName(i)+";\n";
            hashContent += arbol->dibujarArbol(false);
            hashContent += *grupo->getElementName(i) +" ->" + to_string(arbol->raiz->keyValue)

                    + ";\n";
        }
    }
    return hashContent;
}

void Graficador::crearGrafico(string content, string graphName){
    ofstream file("../"+ graphName+".dot");
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
    } else {
        file << content << endl;
        file.close();
        string com = "dot -Tpng ../"+graphName+".dot -o ../"+graphName+".png";
        system(com.c_str());
        cout << "Se genero el grafico correctamente." << endl;
    }
}