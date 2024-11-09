#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include "MyLinkedList.h"
using namespace std;

class MyHashTable {
public: // Recuerden que esto solo lo hacemos para revisar las actividades, normalmente esto no deberia ser publico
    MyLinkedList* tabla; // Arreglo de listas enlazadas para almacenar datos
    int size;  // Cantidad de valores almacenados en la tabla
    int sizeA; // Tamaño del arreglo

    void rehashing(); // Duplicar el tamaño del arreglo actual y sumarle 1
    int getPos(int key); // Calcula la posicion en el arreglo para una llave dada

    MyHashTable(); // Constructor, inicializa el tamaño en 11
    ~MyHashTable(); // Destructor
    bool isEmpty(); // Verifica si la tabla esta vacia
    void put(int key, int value); // Inserta una clave y valor en la tabla
    int get(int key); // Recupera el valor asociado a una clave
    void remove(int key); // Elimina el valor asociado a una clave
};

#endif
