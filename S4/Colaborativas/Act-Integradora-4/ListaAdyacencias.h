#ifndef LISTAADYACENCIAS_H
#define LISTAADYACENCIAS_H

#include <iostream>
#include <map>
#include <string>
#include "Node.h"

using namespace std;

class ListaAdyacencias {
private:
    map<string, Node*> nodos; // clave: IP sin puerto (formato estandarizado)
    int noNodos;

    // Extrae la IP sin el puerto y le pone :0000
    string normalizarIp(const string& ipConPuerto) {
        size_t pos = ipConPuerto.find(':');
        if (pos != string::npos) {
            return ipConPuerto.substr(0, pos) + ":0000";
        }
        return ipConPuerto + ":0000"; // Si no tiene puerto, agrega ":0000"
    }

public:
    ListaAdyacencias() {
        noNodos = 0;
    }

    ~ListaAdyacencias() {
        for (auto& par : nodos) {
            delete par.second;
        }
        nodos.clear();
    }

    void insertarNodo(const string& ipAddress) {
        string ipNormalizada = normalizarIp(ipAddress);
        if (nodos.find(ipNormalizada) != nodos.end()) return;

        Node* nuevoNodo = new Node(ipNormalizada);
        nodos[ipNormalizada] = nuevoNodo;
        noNodos++;
    }

    int insertarRegistro(const string& registroStr) {
        Registro* nuevoRegistro = new Registro(registroStr);
        string ipOriginal = nuevoRegistro->origen.ip;
        string ipNormalizada = normalizarIp(ipOriginal);
        delete nuevoRegistro; // Ya no lo necesitamos, Node hará su propio Registro*

        auto it = nodos.find(ipNormalizada);
        if (it != nodos.end()) {
            it->second->insertRegistro(registroStr);
        } else {
            Node* nuevoNodo = new Node(ipNormalizada);
            nuevoNodo->insertRegistro(registroStr);
            nodos[ipNormalizada] = nuevoNodo;
            noNodos++;
        }

        return 1;
    }

    int getNumeroNodos() const {
        return noNodos;
    }

    void imprimir() const {
        for (const auto& par : nodos) {
            par.second->print();
        }
    }
};

#endif // LISTAADYACENCIAS_H
