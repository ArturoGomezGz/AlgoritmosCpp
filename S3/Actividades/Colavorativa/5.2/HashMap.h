#ifndef HASHMAP_H
#define HASHMAP_H

#include <vector>
#include <stdexcept>
#include "LinkedList.h"
#include <fstream>

// Estructura MapNode que representa un nodo en la lista de claves del HashMap.
struct MapNode {
    string ip;                // Dirección IP asociada a este nodo.
    long ipLong;              // Dirección IP convertida a un valor numérico para facilitar comparaciones.
    LinkedList* value;        // Lista enlazada que almacena los datos asociados a esta IP.
    MapNode* next;            // Puntero al siguiente nodo en la lista.

    // Convierte la dirección IP en un valor numérico.
    // Complejidad: O(1)
    void setIpLong() {
        istringstream iss(ip);
        string octet;
        vector<int> octets;

        while (getline(iss, octet, '.')) {
            int value = stoi(octet);
            if (value < 0 || value > 255) {
                throw invalid_argument("Invalid IP address format");
            }
            octets.push_back(value);
        }

        if (octets.size() != 4) {
            throw invalid_argument("Invalid IP address format");
        }

        ipLong = (static_cast<long>(octets[0]) << 24) |
                 (static_cast<long>(octets[1]) << 16) |
                 (static_cast<long>(octets[2]) << 8) |
                 (static_cast<long>(octets[3]));
    }

    // Constructor que inicializa un nodo con la IP y un puntero al siguiente nodo.
    // Complejidad: O(1)
    MapNode(string ip, MapNode* next) {
        this->ip = ip;
        this->value = nullptr;
        this->next = next;
        this->setIpLong();
    }

    // Constructor que inicializa un nodo con la IP y sin siguiente nodo.
    // Complejidad: O(1)
    MapNode(string ip) : MapNode(ip, nullptr) {}

    // Inserta un nuevo dato en la lista enlazada asociada a la IP.
    // Complejidad: O(n)
    void insert(string data) {
        if (this->value == nullptr) {
            this->value = new LinkedList();
        }
        this->value->insert(data);
    }

    // Imprime la información del nodo y su lista enlazada.
    // Complejidad: O(n)
    void print() {
        cout << "------------ " << this->ip << " ------------" << endl;
        this->value->print();
    }
};

// Clase HashMap que almacena claves (IPs) y sus valores asociados.
class HashMap {
private:
    int size;          // Número de claves en el HashMap.
    MapNode* keys;     // Lista de claves en el HashMap.
public:
    HashMap(); 
    // Constructor: inicializa el HashMap con tamaño 0 y sin claves.

    int length();
    // Retorna el número actual de claves en el HashMap.

    bool isEmpty();
    // Verifica si el HashMap está vacío.

    void insert(string line);
    // Inserta una nueva línea en el HashMap, asociándola a una IP.

    void newIp(string ip);
    // Agrega una nueva dirección IP como clave en el HashMap.

    string getIp(string line);
    // Extrae la dirección IP de una línea de texto.

    void print();
    // Imprime todo el contenido del HashMap.

    void loadTxt(string file);
    // Carga líneas desde un archivo de texto y las inserta en el HashMap.

    void consultar();
};

#endif
