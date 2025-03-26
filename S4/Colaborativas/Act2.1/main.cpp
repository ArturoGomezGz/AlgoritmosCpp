#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Crear una lista enlazada de enteros
    LinkedList<int> listaEnteros;

    // Probar addFirst con 5 elementos
    for (int i = 1; i <= 5; i++) {
        listaEnteros.addFirst(i * 10); // Agregar 50, 40, 30, 20, 10
    }
    cout << "Lista de enteros después de addFirst (50, 40, 30, 20, 10): ";
    listaEnteros.print();

    // Probar addLast con 10 elementos adicionales
    for (int i = 6; i <= 15; i++) {
        listaEnteros.addLast(i * 10); // Agregar 60, 70, ..., 150
    }
    cout << "Lista de enteros después de addLast (60, 70, ..., 150): ";
    listaEnteros.print();

    // Probar deleteData
    listaEnteros.deleteData(30); // Eliminar el valor 30
    cout << "Lista de enteros después de deleteData(30): ";
    listaEnteros.print();

    // Probar deleteAt
    listaEnteros.deleteAt(5); // Eliminar el nodo en la posición 5
    cout << "Lista de enteros después de deleteAt(5): ";
    listaEnteros.print();

    // Probar getData
    cout << "Elemento en la posición 3: " << listaEnteros.getData(3) << endl;

    // Probar updateData (por valor)
    listaEnteros.updateData(50, 55); // Cambiar 50 por 55
    cout << "Lista de enteros después de updateData(50, 55): ";
    listaEnteros.print();

    // Probar updateAt (por posición)
    listaEnteros.updateAt(0, 5); // Cambiar el primer elemento a 5
    cout << "Lista de enteros después de updateAt(0, 5): ";
    listaEnteros.print();

    // Probar findData
    int pos = listaEnteros.findData(100); // Buscar el valor 100
    if (pos != -1) {
        cout << "El valor 100 se encuentra en la posición: " << pos << endl;
    } else {
        cout << "El valor 100 no se encuentra en la lista." << endl;
    }

    // Probar findMidleElement
    cout << "El elemento en el medio de la lista es: " << listaEnteros.findMidleElement() << endl;

    // Probar deleteAll
    listaEnteros.addLast(100); // Agregar un valor duplicado
    listaEnteros.addLast(100);
    cout << "Lista después de agregar valores duplicados (100, 100): ";
    listaEnteros.print();
    int eliminados = listaEnteros.deleteAll(100); // Eliminar todos los nodos con valor 100
    cout << "Se eliminaron " << eliminados << " nodos con el valor 100." << endl;
    cout << "Lista después de deleteAll(100): ";
    listaEnteros.print();

    // Probar getSize
    cout << "Tamaño final de la lista de enteros: " << listaEnteros.getSize() << endl;

    // Crear una lista enlazada de cadenas
    LinkedList<string> listaCadenas;

    // Probar addFirst y addLast con cadenas
    listaCadenas.addFirst("Hola");
    listaCadenas.addLast("Mundo");
    listaCadenas.addLast("!");
    listaCadenas.addFirst("Bienvenidos");
    listaCadenas.addLast("a");
    listaCadenas.addLast("la");
    listaCadenas.addLast("prueba");
    listaCadenas.addLast("de");
    listaCadenas.addLast("LinkedList");
    listaCadenas.addLast("con");
    listaCadenas.addLast("cadenas");
    listaCadenas.addLast("de");
    listaCadenas.addLast("texto");
    listaCadenas.addLast("!");
    cout << "Lista de cadenas después de agregar elementos: ";
    listaCadenas.print();

    // Probar updateData con cadenas
    listaCadenas.updateData("Hola", "Saludos");
    cout << "Lista de cadenas después de updateData('Hola', 'Saludos'): ";
    listaCadenas.print();

    // Probar deleteAt con cadenas
    listaCadenas.deleteAt(5); // Eliminar el nodo en la posición 5
    cout << "Lista de cadenas después de deleteAt(5): ";
    listaCadenas.print();

    // Probar findData con cadenas
    pos = listaCadenas.findData("LinkedList");
    if (pos != -1) {
        cout << "La palabra 'LinkedList' se encuentra en la posición: " << pos << endl;
    } else {
        cout << "La palabra 'LinkedList' no se encuentra en la lista." << endl;
    }

    // Probar getSize con cadenas
    cout << "Tamaño final de la lista de cadenas: " << listaCadenas.getSize() << endl;

    return 0;
}
