#include "MyHeap.h"
#include <iostream>
using namespace std;

// Descripción: Inicializa un heap vacío con un tamaño de 7 y valores en cero
// Complejidad en el peor de los casos: O(n) - debido a la inicialización del arreglo.
// Complejidad en el mejor de los casos: O(n)
MyHeap::MyHeap() {
    this->len = 7;
    this->size = 0;
    this->values = new int[len];
    for (int i = 0; i < len; i++) {
        this->values[i] = 0;
    }
}

// Descripción: Construye un heap a partir de un arreglo dado de valores.
// Complejidad en el peor de los casos: O(n) - debido a las llamadas a heapifyDown
// Complejidad en el mejor de los casos: O(n)
MyHeap::MyHeap(int* valores, int size) {
    this->len = size + 7;
    this->size = size;
    this->values = new int[len];
    for (int i = 0; i < size; i++) {
        this->values[i] = valores[i];
    }
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapifyDown(i);
    }
}

// Inserta un valor en el heap
// Complejidad en el peor de los casos: O(log n) - debido a heapifyUp .
// Complejidad en el mejor de los casos: O(1) - si no es necesario llamar a heapifyUp
void MyHeap::push(int n) {
    if (size == len) {
        len += 7;
        int* newValues = new int[len];
        for (int i = 0; i < size; i++) {
            newValues[i] = values[i];
        }
        delete[] values;
        values = newValues;
    }
    values[size] = n;
    size++;
    heapifyUp(size - 1);
}

// Elimina un valor del heap
// Complejidad en el peor de los casos: O(log n) - debido a heapifyDown.
// Complejidad en el mejor de los casos: O(1) - si el heap tiene un solo elemento.
void MyHeap::pop() {
    if (size == 0) return;
    values[0] = values[size - 1];
    size--;
    heapifyDown(0);
}

// Devuelve el siguiente elemento en salir sin borrarlo
// Complejidad en el peor de los casos: O(1)
// Complejidad en el mejor de los casos: O(1)
int MyHeap::top() {
    if (size == 0) return -1;
    return values[0];
}

// Regresa true si el heap está vacio
// Complejidad en el peor de los casos: O(1)
// Complejidad en el mejor de los casos: O(1)
bool MyHeap::isEmpty() {
    return size == 0;
}

// Regresa el número de elementos almacenados en el heap (no el tamaño maximo)
// Complejidad en el peor de los casos: O(1)
// Complejidad en el mejor de los casos: O(1)
int MyHeap::length() {
    return this->size;
}

// Imprime los atributos del heap
// Complejidad en el peor de los casos: O(n) - debido a la impresión de cada elemento
// Complejidad en el mejor de los casos: O(n)
void MyHeap::imprimir() {
    cout << "arbol size: " << this->size << " len:" << this->len << endl;
    for (int i = 0; i < this->size; i++) {
        cout << values[i] << ",";
    }
    cout << endl;
}

// Métodos auxiliares para mantener la propiedad del heap

// Mantiene la propiedad del heap subiendo el elemento en index a su posición correcta
// Complejidad en el peor de los casos: O(log n)
// Complejidad en el mejor de los casos: O(1) - si no es necesario mover el elemento.
void MyHeap::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (values[index] > values[parent]) {
            swap(values[index], values[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

// Mantiene la propiedad del heap bajando el elemento en index a su posición correcta.
// Complejidad en el peor de los casos: O(log n)
// Complejidad en el mejor de los casos: O(1) - si no es necesario mover el elemento.
void MyHeap::heapifyDown(int index) {
    while (index * 2 + 1 < size) {
        int leftChild = index * 2 + 1;
        int rightChild = leftChild + 1;
        int largest = leftChild;
        if (rightChild < size && values[rightChild] > values[leftChild]) {
            largest = rightChild;
        }
        if (values[index] < values[largest]) {
            swap(values[index], values[largest]);
            index = largest;
        } else {
            break;
        }
    }
}
