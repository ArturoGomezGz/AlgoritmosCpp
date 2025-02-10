#ifndef MYLINKEDLIST_h
#define MYLINKEDLIST_h

#include <string>

// Estructura que representa un nodo en la lista enlazada
struct MyNodoLL {
    int data; // Dato en el nodo
    MyNodoLL* next; // Puntero al siguiente nodo

    MyNodoLL(int data, MyNodoLL* next) {
        this->data = data;
        this->next = next;
    }

    MyNodoLL(int data) : MyNodoLL(data, nullptr) {}
};

// Clase que representa la lista enlazada
class MyLinkedList {
public:
    int size;
    MyNodoLL *head, *tail;

    MyLinkedList(); // Constructor por defecto
    ~MyLinkedList(); // Destructor
    int length(); // Devuelve el largo de la lista
    bool isEmpty(); // Revisa si la lista esta vacia
    int first(); // Devuelve el primer elemento
    int last();  // Devuelve el ultimo elemento
    int getAt(int pos); // Obtiene el elemento en una posicion especifica
    void setAt(int pos, int data); // Modifica el valor en una posicion especifica
    void insertFirst(int data); // Inserta un elemento al inicio
    void insertLast(int data); // Inserta un elemento al final
    void insertAt(int pos, int data); // Inserta un elemento en una posicion especifica
    void removeFirst(); // Elimina el primer elemento
    void removeLast(); // Elimina el ultimo elemento
    void removeAt(int pos); // Elimina el elemento en una posicion especifica

    friend std::ostream& operator<<(std::ostream& os, const MyLinkedList& ll);
    // Imprime los elementos de la lista en orden, separados por comas
};

#endif
