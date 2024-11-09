#include "MyLinkedList.h"
#include <iostream>
#include <stdexcept>

using namespace std;

// Constructor: inicializa una lista enlazada vacia
MyLinkedList::MyLinkedList() : size(0), head(nullptr), tail(nullptr) {}

// Destructor: elimina todos los nodos de la lista
MyLinkedList::~MyLinkedList() {
    while (!isEmpty()) {
        removeFirst();
    }
}

// Retorna el largo de la lista
int MyLinkedList::length() {
    return size;
}

// Verifica si la lista esta vacia
bool MyLinkedList::isEmpty() {
    return size == 0;
}

// Retorna el primer elemento; lanza una excepcion si esta vacia
int MyLinkedList::first() {
    if (isEmpty()) {
        throw invalid_argument("La lista esta vacia");
    }
    return head->data;
}

// Retorna el ultimo elemento; lanza una excepcion si esta vacia
int MyLinkedList::last() {
    if (isEmpty()) {
        throw invalid_argument("La lista esta vacia");
    }
    return tail->data;
}

// Obtiene el elemento en la posicion dada; lanza excepcion si es invalida
int MyLinkedList::getAt(int pos) {
    if (pos < 0 || pos >= size) {
        throw invalid_argument("Posicion invalida");
    }
    MyNodoLL* current = head;
    for (int i = 0; i < pos; i++) {
        current = current->next;
    }
    return current->data;
}

// Establece el valor de un nodo en una posicion especifica; lanza excepcion si es invalida
void MyLinkedList::setAt(int pos, int data) {
    if (pos < 0 || pos >= size) {
        throw invalid_argument("Posicion invalida");
    }
    MyNodoLL* current = head;
    for (int i = 0; i < pos; i++) {
        current = current->next;
    }
    current->data = data;
}

// Inserta un elemento al inicio de la lista
void MyLinkedList::insertFirst(int data) {
    MyNodoLL* newNode = new MyNodoLL(data, head);
    head = newNode;
    if (size == 0) {
        tail = newNode;
    }
    size++;
}

// Inserta un elemento al final de la lista
void MyLinkedList::insertLast(int data) {
    MyNodoLL* newNode = new MyNodoLL(data);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

// Inserta un elemento en una posicion; lanza excepcion si es invalida
void MyLinkedList::insertAt(int pos, int data) {
    if (pos < 0 || pos > size) {
        throw invalid_argument("Posicion invalida");
    }
    if (pos == 0) {
        insertFirst(data);
    } else if (pos == size) {
        insertLast(data);
    } else {
        MyNodoLL* prev = head;
        for (int i = 0; i < pos - 1; i++) {
            prev = prev->next;
        }
        MyNodoLL* newNode = new MyNodoLL(data, prev->next);
        prev->next = newNode;
        size++;
    }
}

// Elimina el primer elemento de la lista
void MyLinkedList::removeFirst() {
    if (isEmpty()) {
        throw invalid_argument("La lista esta vacia");
    }
    MyNodoLL* temp = head;
    head = head->next;
    delete temp;
    size--;
    if (size == 0) {
        tail = nullptr;
    }
}

// Elimina el ultimo elemento; lanza excepcion si la lista esta vacia
void MyLinkedList::removeLast() {
    if (isEmpty()) {
        throw invalid_argument("La lista esta vacia");
    }
    if (size == 1) {
        delete head;
        head = tail = nullptr;
    } else {
        MyNodoLL* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    size--;
}

// Elimina un elemento en una posicion; lanza excepcion si es invalida
void MyLinkedList::removeAt(int pos) {
    if (pos < 0 || pos >= size) {
        throw invalid_argument("Posicion invalida");
    }
    if (pos == 0) {
        removeFirst();
    } else if (pos == size - 1) {
        removeLast();
    } else {
        MyNodoLL* prev = head;
        for (int i = 0; i < pos - 1; i++) {
            prev = prev->next;
        }
        MyNodoLL* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
        size--;
    }
}

// Sobrecarga del operador << para imprimir la lista
ostream& operator<<(ostream& os, const MyLinkedList& ll) {
    MyNodoLL* current = ll.head;
    while (current != nullptr) {
        os << current->data;
        if (current->next != nullptr) {
            os << ",";
        }
        current = current->next;
    }
    return os;
}
