#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "structs.h"

using namespace std;

struct Node {
    IpAddress ip; // Formato: 36.29.138.97
    vector<Registro> registros; // Vector de registros
    int grado; // Grado del nodo, que es el número de registros que tiene este nodo

    Node(string ipAddress) {
        ip.set(ipAddress);
        grado = 0; // Inicializa el grado a 0
    }

    void insertRegistro(string registro) {
        Registro reg(registro); // Crea un nuevo registro a partir de la cadena proporcionada

        // Buscamos la posicion correcta para insertar el registro según su fecha utilizando el valor comparable
        for (auto it = registros.begin(); it != registros.end(); ++it) {
            if (reg.date.dateComparableValue < it->date.dateComparableValue) {
                registros.insert(it, reg); // Inserta el registro antes del primer registro con fecha posterior
                grado++; // Incrementa el grado del nodo
                return;
            }
        }
    }

    void print() {
        cout << "Registros para IP " << ip.ip << ":" << endl;
        for (const auto& registro : registros) {
            cout << registro.value << endl;
        }
        cout << "Total de registros: " << grado << endl;
    }

};
    

#endif // NODE_H