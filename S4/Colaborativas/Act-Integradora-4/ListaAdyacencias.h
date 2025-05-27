#ifndef LISTAADYACENCIAS_H
#define LISTAADYACENCIAS_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
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

    // Bubble sort para ordenar vector<Node*> por grado descendente
    void bubbleSortPorGradoDesc(vector<Node*>& nodosVec) const {
        size_t n = nodosVec.size();
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n - 1 - i; ++j) {
                if (nodosVec[j]->grado < nodosVec[j + 1]->grado) {
                    swap(nodosVec[j], nodosVec[j + 1]);
                }
            }
        }
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

    // Método para imprimir el top N nodos con mayor grado
    void imprimirTopNodosPorGrado(int top) const {
        vector<Node*> nodosVector;
        for (const auto& par : nodos) {
            nodosVector.push_back(par.second);
        }

        bubbleSortPorGradoDesc(nodosVector);

        if (top > (int)nodosVector.size()) {
            top = nodosVector.size();
        }

        for (int i = 0; i < top; ++i) {
            nodosVector[i]->print();
        }
    }

    vector<Node*> obtenerTopNodosPorGrado(int top) const {
        vector<Node*> nodosVector;
        for (const auto& par : nodos) {
            nodosVector.push_back(par.second);
        }

        bubbleSortPorGradoDesc(nodosVector);

        if (top > (int)nodosVector.size()) {
            top = nodosVector.size();
        }

        nodosVector.resize(top);
        return nodosVector;
    }

};

#endif // LISTAADYACENCIAS_H
