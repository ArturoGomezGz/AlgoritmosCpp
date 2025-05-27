#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include "structs.h"

using namespace std;

struct Node {
    IpAddress ip; // Formato: 36.29.138.97
    vector<Registro*> registros; // Vector de punteros a registros
    int grado; // Grado del nodo, que es el número de registros que tiene este nodo

    Node(string ipAddress) {
        ip.set(ipAddress);
        grado = 0; // Inicializa el grado a 0
    }

    ~Node() {
        // Liberar memoria de los registros creados dinámicamente
        for (auto reg : registros) {
            delete reg;
        }
    }

    void insertRegistro(string registro) {
        Registro* reg = new Registro(registro); // Crea un nuevo registro dinámicamente

        // Busca la posición correcta para insertar el registro según su fecha
        for (auto it = registros.begin(); it != registros.end(); ++it) {
            if (reg->date.dateComparableValue < (*it)->date.dateComparableValue) {
                registros.insert(it, reg); // Inserta antes del primer registro con fecha posterior
                grado++;
                return;
            }
        }

        // Si no se insertó en el ciclo, va al final
        registros.push_back(reg);
        grado++;
    }

    void print() {
        cout << "Registros para IP " << ip.ip << ":" << endl;
        for (const auto& registro : registros) {
            cout << registro->value << endl; // Ajusta acceso con puntero
        }
    }

    void printGrado() {
        cout << "Grado del nodo " << ip.ip << ": " << grado << endl;
    }
    
};

#endif
