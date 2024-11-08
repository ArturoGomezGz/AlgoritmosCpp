#include "MyHeap.h"
#include <iostream>
using namespace std;

int main() {
    // Crear un objeto de MyHeap
    MyHeap heap;

    // Prueba de insercion de varios elementos
    cout << "Insertando elementos en el heap..." << endl;
    heap.push(10);
    heap.push(5);
    heap.push(3);
    heap.push(7);
    heap.push(2);
    heap.push(15);
    heap.push(1);
    heap.push(8);  // Esto debe desencadenar el crecimiento del array

    // Imprimir el heap despues de las inserciones iniciales
    cout << "Estado del heap despues de inserciones:" << endl;
    heap.imprimir();

    // Verificar el elemento en la cima
    cout << "Elemento en la cima (deberia ser 1): " << heap.top() << endl;

    // Probar eliminacion y verificar reestructuracion
    cout << "Eliminando el elemento de la cima (1)..." << endl;
    heap.pop();
    cout << "Estado del heap despues de eliminar el elemento de la cima:" << endl;
    heap.imprimir();

    // Insertar mas elementos y verificar el orden
    cout << "Insertando 4, 0 y 9 en el heap..." << endl;
    heap.push(4);
    heap.push(0);
    heap.push(9);

    // Imprimir el heap despues de nuevas inserciones
    cout << "Estado del heap despues de mas inserciones:" << endl;
    heap.imprimir();

    // Verificar el elemento en la cima nuevamente
    cout << "Nuevo elemento en la cima (deberia ser 0): " << heap.top() << endl;

    // Eliminar varios elementos y verificar estructura
    cout << "Eliminando elementos de la cima varias veces..." << endl;
    heap.pop();  // Deberia eliminar 0
    heap.pop();  // Deberia eliminar 2
    cout << "Estado del heap despues de eliminar dos elementos:" << endl;
    heap.imprimir();

    // Comprobar si el heap esta vacio
    cout << "El heap esta vacio? " << (heap.isEmpty() ? "Si" : "No") << endl;

    // Insertar mas elementos para verificar capacidad de redimensionamiento
    cout << "Insertando 11, 6, 14, 5, 3, 12 en el heap..." << endl;
    heap.push(11);
    heap.push(6);
    heap.push(14);
    heap.push(5);
    heap.push(3);
    heap.push(12);

    // Imprimir el heap despues de varias inserciones
    cout << "Estado final del heap:" << endl;
    heap.imprimir();

    // Verificar el tamano actual del heap
    cout << "Tamano actual del heap: " << heap.length() << endl;

    // Esperar entrada para finalizar el programa
    cout << "Presiona Enter para finalizar...";
    cin.get();

    return 0;
}
