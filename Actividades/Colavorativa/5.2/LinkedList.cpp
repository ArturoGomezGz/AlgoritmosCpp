#include "LinkedList.h"

// Constructor: inicializa la lista enlazada con tamaño 0 y sin nodos.
// Complejidad: O(1)
LinkedList::LinkedList() {
    this->size = 0;
    this->head = nullptr;
}

// Retorna el tamaño actual de la lista enlazada.
// Complejidad: O(1)
int LinkedList::length() {
    return this->size;
}

// Verifica si la lista enlazada está vacía.
// Complejidad: O(1)
bool LinkedList::isEmpty() {
    return this->size == 0;
}

// Inserta un nuevo nodo en la lista en orden ascendente según dateCompare.
// Complejidad: O(n)
void LinkedList::insert(string data) {
    Node* nodo = new Node(data);
    if (this->isEmpty()) { // Si la lista está vacía, el nodo se convierte en la cabeza.
        this->head = nodo;
    } else if (nodo->dateCompare < this->head->dateCompare) { // Inserta antes de la cabeza si es menor.
        nodo->next = this->head;
        this->head = nodo;
    } else { // Busca la posición correcta para insertar el nodo.
        Node* current = this->head;
        while (current->next != nullptr && current->next->dateCompare < nodo->dateCompare) {
            current = current->next;
        }
        nodo->next = current->next;
        current->next = nodo;
    }
    this->size++;
}

// Imprime el contenido completo de la lista enlazada.
// Complejidad: O(n)
void LinkedList::print() {
    Node* current = this->head;
    while (current != nullptr) {
        current->print();
        current = current->next;
    }
}
