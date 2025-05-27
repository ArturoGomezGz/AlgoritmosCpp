#ifndef BFS_AUX_H
#define BFS_AUX_H

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <stack>
#include <vector>
#include <functional>
#include "ListaAdyacencias.h"

using namespace std;

struct CompararGrado {
    bool operator()(const Node* a, const Node* b) const {
        return a->grado < b->grado; // max heap: mayor grado primero
    }
};

void bfsDesdeIP(ListaAdyacencias& grafo, string ipInicio,
                unordered_map<string, int>& distancias,
                unordered_map<string, string>& padres) {
    unordered_map<string, bool> visitado;
    queue<string> cola;

    cola.push(ipInicio);
    distancias[ipInicio] = 0;
    visitado[ipInicio] = true;

    while (!cola.empty()) {
        string actual = cola.front();
        cola.pop();

        Node* nodo = grafo.obtenerNodo(actual);
        if (!nodo) continue;

        for (const auto& reg : nodo->registros) {
            string vecino = reg->destino.ip;
            if (!visitado[vecino]) {
                visitado[vecino] = true;
                distancias[vecino] = distancias[actual] + 1;
                padres[vecino] = actual;
                cola.push(vecino);
            }
        }
    }
}

void guardarDistancias(const unordered_map<string, int>& distancias) {
    ofstream salida("distancia_botmaster.txt");
    for (const auto& par : distancias) {
        salida << par.first << " " << par.second << endl;
    }
    salida.close();
}

void guardarCamino(const unordered_map<string, string>& padres, const string& ipFinal) {
    stack<string> camino;
    string actual = ipFinal;

    while (padres.find(actual) != padres.end()) {
        camino.push(actual);
        actual = padres.at(actual);
    }
    camino.push(actual);

    ofstream salida("ataque_botmaster.txt");
    while (!camino.empty()) {
        salida << camino.top() << endl;
        camino.pop();
    }
    salida.close();
}

void guardarGrados(const map<string, Node*>& nodos) {
    ofstream salida("grados_ips.txt");
    for (const auto& par : nodos) {
        salida << par.first << " " << par.second->grado << endl;
    }
    salida.close();
}

vector<Node*> obtenerTopConHeap(const map<string, Node*>& nodos, int top) {
    priority_queue<Node*, vector<Node*>, CompararGrado> heap;
    for (const auto& par : nodos) {
        heap.push(par.second);
    }
    
    vector<Node*> topIPs;
    for (int i = 0; i < top && !heap.empty(); ++i) {
        topIPs.push_back(heap.top());
        heap.pop();
    }
    
    ofstream salida("mayores_grados_ips.txt");
    for (Node* nodo : topIPs) {
        salida << nodo->ip.ip << " " << nodo->grado << endl;
    }
    salida.close();

    return topIPs;
}

#endif
