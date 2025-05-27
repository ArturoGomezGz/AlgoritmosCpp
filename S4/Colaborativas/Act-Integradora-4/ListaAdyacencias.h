#ifndef LISTAADYACENCIAS_H
#define LISTAADYACENCIAS_H

#include <iostream>
#include <vector>
#include <string>
#include "Node.h"

using namespace std;

class ListaAdyacencias {
private:
    vector<Node*> nodos; // vector de nodos en lugar de map
    int noNodos;

    // Extrae la IP sin el puerto y le pone :0000
    string normalizarIp(const string& ipConPuerto) {
        size_t pos = ipConPuerto.find(':');
        if (pos != string::npos) {
            return ipConPuerto.substr(0, pos) + ":0000";
        }
        return ipConPuerto + ":0000"; // Si no tiene puerto, agrega ":0000"
    }
    
    // Método auxiliar para buscar un nodo por IP
    Node* buscarNodo(const string& ip) {
        for (Node* nodo : nodos) {
            if (nodo->ip.ip == ip) {
                return nodo;
            }
        }
        return nullptr;
    }

public:
    ListaAdyacencias() {
        noNodos = 0;
    }

    ~ListaAdyacencias() {
        for (Node* nodo : nodos) {
            delete nodo;
        }
        nodos.clear();
    }

    void insertarNodo(const string& ipAddress) {
        string ipNormalizada = normalizarIp(ipAddress);
        if (buscarNodo(ipNormalizada) != nullptr) return;

        Node* nuevoNodo = new Node(ipNormalizada);
        nodos.push_back(nuevoNodo);
        noNodos++;
    }

    int insertarRegistro(const string& registroStr) {
        Registro* nuevoRegistro = new Registro(registroStr);
        string ipOriginal = nuevoRegistro->origen.ip;
        string ipNormalizada = normalizarIp(ipOriginal);
        delete nuevoRegistro; // Ya no lo necesitamos, Node hará su propio Registro*

        Node* nodoExistente = buscarNodo(ipNormalizada);
        if (nodoExistente != nullptr) {
            nodoExistente->insertRegistro(registroStr);
        } else {
            Node* nuevoNodo = new Node(ipNormalizada);
            nuevoNodo->insertRegistro(registroStr);
            nodos.push_back(nuevoNodo);
            noNodos++;
        }

        return 1;
    }

    int getNumeroNodos() const {
        return noNodos;
    }

    void imprimir() const {
        for (const Node* nodo : nodos) {
            nodo->print();
        }
    }
    
};

#endif // LISTAADYACENCIAS_H
