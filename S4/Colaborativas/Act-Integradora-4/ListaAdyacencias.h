#ifndef LISTAADYACENCIAS_H
#define LISTAADYACENCIAS_H

#include <iostream>
#include <vector>
#include "Node.h"

using namespace std;

class ListaAdyacencias
{
public:
    ListaAdyacencias(){
        noNodos = 0; // Inicializa el contador de nodos a 0
    }
    
    ~ListaAdyacencias() {
        // Liberar memoria de los nodos
        for (Node* nodo : nodos) {
            delete nodo;
        }
        nodos.clear();
    }

    void insertarNodo(string registro){
        // Crea un nuevo nodo con la IP del registro
        Node* nuevoNodo = new Node(registro);
        
        // Buscar la posición correcta según ipComparableValue
        for (auto it = nodos.begin(); it != nodos.end(); ++it) {
            if (nuevoNodo->ip.ipComparableValue < (*it)->ip.ipComparableValue) {
                // Insertar el nodo en la posición encontrada
                nodos.insert(it, nuevoNodo);
                noNodos++;
                return;
            }
        }
        
        // Si llegamos aquí, el nodo debe ir al final
        nodos.push_back(nuevoNodo);
        noNodos++;
    }

    int insertarRegistro(string registro) {
        Registro nuevoRegistro(registro);
        // Buscar el nodo correspondiente a la IP del registro
        for (Node* nodo : nodos) {
            if (nodo->ip.ipComparableValue == nuevoRegistro.origen.ipComparableValue) {
                nodo->insertRegistro(registro);
                return 1; // Registro insertado correctamente
            }
        }
        // Si no se encontró el nodo se retorna 0
        return 0;
    }

    void print() {
        cout << "Lista de adyacencias:" << endl;
        for (Node* nodo : nodos) {
            cout << "IP: " << nodo->ip.ip << endl;
            nodo->print();
        }
    }

    Node* getNodo(int index) {
        if (index < 0 || index >= noNodos) {
            return nullptr; // Retorna nullptr si el índice es inválido
        }
        return nodos[index]; // Retorna el nodo en la posición indicada
    }

private:
    vector<Node*> nodos; // Vector de punteros a nodos
    int noNodos; // Cantidad de nodos en la lista de adyacencias
};

#endif //LISTAADYACENCIAS_H
