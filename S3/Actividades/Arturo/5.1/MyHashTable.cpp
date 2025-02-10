#include "MyHashTable.h"
#include <stdexcept>
#include <cmath>

// Constructor: configura la tabla hash con un tamaño inicial de 11
// Complejidad: O(1)
MyHashTable::MyHashTable() {
    this->size = 0;
    this->sizeA = 11;
    this->tabla = new MyLinkedList[this->sizeA];
}

// Destructor: libera la memoria que fue asignada para la tabla
// Complejidad: O(n), siendo n el numero de elementos en la tabla
MyHashTable::~MyHashTable() {
    delete[] tabla;
}

// Chequea si la tabla esta vacia
// Complejidad: O(1)
bool MyHashTable::isEmpty() {
    return size == 0;
}

int MyHashTable::getPos(int key) {
    size_t hashC = hash<int>{}(key);
    int hashCode = static_cast<int>(hashC);
    return abs(hashCode) % this->sizeA;
}

// Agrega una nueva clave con su valor a la tabla
// Complejidad promedio: O(1), peor caso (rehashing) O(n)
void MyHashTable::put(int key, int value) {
    int pos = getPos(key);
    MyNodoLL* current = tabla[pos].head;
    while (current != nullptr) {
        // Si la clave ya existe, actualizamos el valor
        if (current->data == value) {
            current->data = value;
            return;
        }
        current = current->next;
    }
    // Si la clave es nueva, se inserta al inicio de la lista en la posicion correspondiente
    tabla[pos].insertFirst(value);
    size++;
    // Si el factor de carga es mayor a 0.75, se hace rehashing
    if (static_cast<double>(size) / sizeA > 0.75) {
        rehashing();
    }
}

// Obtiene el valor asociado a una clave dada
// Complejidad promedio: O(1), peor caso O(n/m) donde n es el numero de elementos y m es el tamaño del arreglo
int MyHashTable::get(int key) {
    int pos = getPos(key);
    MyNodoLL* current = tabla[pos].head;
    while (current != nullptr) {
        // Chequea si el nodo actual tiene la clave buscada
        if (current->data == key) {
            return current->data;
        }
        current = current->next;
    }
    throw invalid_argument("Clave no encontrada");
}

// Elimina un par clave-valor de la tabla
// Complejidad promedio: O(1), peor caso O(n/m)
void MyHashTable::remove(int key) {
    int pos = getPos(key);
    MyNodoLL* current = tabla[pos].head;
    int index = 0;
    while (current != nullptr) {
        if (current->data == key) {
            tabla[pos].removeAt(index);
            size--;
            return;
        }
        current = current->next;
        index++;
    }
    throw invalid_argument("Clave no encontrada");
}

// Realiza el rehashing aumentando el tamaño de la tabla al doble mas uno
// Complejidad: O(n), siendo n el numero de elementos en la tabla
void MyHashTable::rehashing() {
    int newSizeA = sizeA * 2 + 1;
    MyLinkedList* newTable = new MyLinkedList[newSizeA];
    // Reubica todos los elementos en la nueva tabla
    for (int i = 0; i < sizeA; i++) {
        MyNodoLL* current = tabla[i].head;
        while (current != nullptr) {
            int newPos = abs(static_cast<int>(hash<int>{}(current->data))) % newSizeA;
            newTable[newPos].insertFirst(current->data);
            current = current->next;
        }
    }
    delete[] tabla;
    tabla = newTable;
    sizeA = newSizeA;
}
