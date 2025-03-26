#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    Node(T valor) : valor(valor) {}
    ~Node() {}
    T valor;
    Node* next = nullptr;
};

template <typename T>
class LinkedList
{
public:
    // Constructor: Inicializa una lista vacía
    // Complejidad: O(1)
    LinkedList() {
        this->head = nullptr;
        this->size = 0;
    }

    // Constructor copia: Crea una copia de otra lista enlazada
    // Complejidad: O(n)
    LinkedList(LinkedList<T>& copy) {
        this->head = nullptr;
        this->size = 0;
        Node<T>* current = copy.head;
        while (current != nullptr) {
            this->addLast(current->valor);
            current = current->next;
        }
    }

    // Destructor: Libera la memoria de todos los nodos
    // Complejidad: O(n)
    ~LinkedList() {
        Node<T>* current = this->head; // Guardamos en actual el primer elemento de la lista 
        // Iteramos elemento por elemento para eliminarlo y liberar la memoria
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        this->size = 0;
    }

    // Agrega un elemento al inicio de la lista
    // Complejidad: O(1)
    void addFirst(T valor) {
        Node<T>* newNode = new Node<T>(valor); // Creamos un nuevo nodo con el valor especificado
        newNode->next = this->head; // Sustituimos el siguiente nodo del nuevo nodo por el primer nodo de la lista
        this->head = newNode; //Guardamos el nuevo nodo como el primer nodo de la lista
        this->size++; // Incrementamos el tamaño de la lista 
    }

    // Agrega un elemento al final de la lista
    // Complejidad: O(n)
    void addLast(T valor) {
        Node<T>* newNode = new Node<T>(valor);
        if (this->head == nullptr) { // Si la lista está vacía, el nuevo nodo es el primer nodo
            this->head = newNode;
        } else {
            Node<T>* current = this->head; // Guardamos en actual el primer elemento de la lista 
            while (current->next != nullptr) { // Iteramos hasta llegar al último nodo
                current = current->next;
            }
            current->next = newNode; // Sustituimos el siguiente nodo del último nodo por el nuevo nodo
        }
        this->size++; // Incrementamos el tamaño de la lista
    }

    // Elimina el primer nodo que contiene el valor especificado
    // Complejidad: O(n)
    int deleteData(T valor) {
        Node<T>* current = this->head; // Guardamos en actual el primer elemento de la lista 
        Node<T>* previous = nullptr; // Guardamos en previous el elemento anterior a current  
        
        // Iternamos hasta encontrar el nodo con el valor especificado para despues eliminarlo 
        while (current != nullptr) {
            if (current->valor == valor) {
                if (previous == nullptr) {
                    this->head = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current;
                this->size--; // Decrementamos el tamaño de la lista
                return 1; // Terminamos el proceso // Se encontró y eliminó el valor
            }
            previous = current;
            current = current->next;
        }
        return 0; // Terminamos el proceso // No se encontró el valor
    }

    // Elimina el nodo en la posición especificada
    // Complejidad: O(n)
    int deleteAt(int position) {
        if (position < 0 || this->head == nullptr || position >= this->size) return 0; // Terminamos el proceso // Posición inválida o lista vacía

        Node<T>* current = this->head; // Guardamos en actual el primer elemento de la lista 
        Node<T>* previous = nullptr; // Guardamos en previous el elemento anterior a current

        if (position == 0) {
            this->head = current->next;
            delete current;
            this->size--; // Decrementamos el tamaño de la lista
            return 1; // Terminamos el proceso
        }

        int pos = 0;
        while (current != nullptr && pos < position) {
            previous = current;
            current = current->next;
            pos++;
        }

        if (current == nullptr) return 0; // Terminamos el proceso

        previous->next = current->next;
        delete current;
        this->size--; // Decrementamos el tamaño de la lista
        return 1; // Terminamos el proceso
    }

    // Obtiene el valor del nodo en la posición especificada
    // Complejidad: O(n)
    T getData(int position) {
        if (position < 0 || this->head == nullptr || position >= this->size) return T(); // Posición inválida o lista vacía

        Node<T>* current = this->head; // Guardamos en actual el primer elemento de la lista 
        int pos = 0;
        while (current != nullptr && pos < position) {
            current = current->next;
            pos++;
        }

        if (current == nullptr) return T(); // Posición fuera de rango

        return current->valor; // Retorna el valor del nodo en la posición especificada
    }

    // Actualiza el valor de un nodo que contiene un valor específico
    // Complejidad: O(n)
    int updateData(T oldValue, T newValue) {
        Node<T>* current = this->head; // Guardamos en actual el primer elemento de la lista 
        while (current != nullptr) {
            if (current->valor == oldValue) {
                current->valor = newValue;
                return 1; // Terminamos el proceso // Se encontró y actualizó el valor
            }
            current = current->next;
        }
        return 0; // Terminamos el proceso // No se encontró el valor
    }

    // Actualiza el valor del nodo en la posición especificada
    // Complejidad: O(n)
    int updateAt(int position, T newValue) {
        if (position < 0 || this->head == nullptr || position >= this->size) return 0; // Terminamos el proceso // Posición inválida o lista vacía

        Node<T>* current = this->head; // Guardamos en actual el primer elemento de la lista 
        int pos = 0;
        while (current != nullptr && pos < position) {
            current = current->next;
            pos++;
        }

        if (current == nullptr) return 0; // Terminamos el proceso

        current->valor = newValue;
        return 1; // Terminamos el proceso
    }

    // Encuentra la posición del primer nodo que contiene el valor especificado
    // Complejidad: O(n)
    int findData(T valor) {
        Node<T>* current = this->head; // Guardamos en actual el primer elemento de la lista 
        int pos = 0;
        while (current != nullptr) {
            if (current->valor == valor) {
                return pos; // Retorna la posición encontrada
            }
            current = current->next;
            pos++;
        }
        return -1; // No se encontró el valor
    }

    // Encuentra el elemento en el medio de la lista
    // Complejidad: O(n)
    T findMidleElement() {
        // Usamos tednica de doble puntero, tecnica aprendida con leetcode
        // https://leetcode.com/problems/trapping-rain-water/description/
        Node<T>* slow = this->head;
        Node<T>* fast = this->head;

        // Iteramos hasta que el puntero rápido llegue al final de la lista
        // Al final, el puntero lento estará en el medio de la lista ya que se mueve a la mitad de la velocidad del puntero rápido
        // En caso de que la lista tenga un número par de elementos, el puntero lento estará en el nodo de la izquierda
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->valor; // Retorna el valor del nodo en el medio
    }

    // Elimina todos los nodos que contienen el valor especificado
    // Complejidad: O(n)
    int deleteAll(T valor) {
        Node<T>* current = this->head; // Guardamos en actual el primer elemento de la lista 
        Node<T>* previous = nullptr; // Guardamos en previous el elemento anterior a current
        int count = 0;
        while (current != nullptr) {  // Iteramos hasta encontrar el nodo con el valor especificado para después eliminarlo
            if (current->valor == valor) { // Si encontramos el valor, lo eliminamos y continuamos con la búsqueda
                if (previous == nullptr) {
                    this->head = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current; // Eliminamos el nodo
                this->size--; // Decrementamos el tamaño de la lista
                count++; // Incrementamos el contador de nodos eliminados
                current = (previous == nullptr) ? this->head : previous->next; // Actualizamos el puntero actual
            } else {
                previous = current;
                current = current->next; // Pasamos al siguiente nodo
            }
        }
        return count == 0 ? -1 : count; // Retorna el número de nodos eliminados o -1 si no se encontró el valor
    }

    // Imprime todos los elementos de la lista
    // Complejidad: O(n)
    void print() {
        Node<T>* current = this->head; // Guardamos en actual el primer elemento de la lista 
        while (current != nullptr) {
            cout << current->valor << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Retorna el tamaño de la lista
    // Complejidad: O(1)
    int getSize() const {
        return this->size; // Retorna el tamaño de la lista
    }

private:
    Node<T>* head;
    int size;
};

#endif //LINKEDLIST_H