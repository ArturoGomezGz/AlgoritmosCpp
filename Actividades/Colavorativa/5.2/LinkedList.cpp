#include "LinkedList.h"

LinkedList::LinkedList(){
    this->size = 0;
    this->head = nullptr;
}

int LinkedList::length(){
    return this->size;
}

bool LinkedList::isEmpty(){
    return this->size == 0;
}

void LinkedList::insert(string data){
    Node* nodo = new Node(data); // Create a new node
    if (this->isEmpty()) {
        this->head = nodo;
    } else if (nodo->dateCompare < this->head->dateCompare) {
        nodo->next = this->head;
        this->head = nodo;
    } else {
        Node* current = this->head;
        while (current->next != nullptr && current->next->dateCompare < nodo->dateCompare) {
            current = current->next;
        }
        nodo->next = current->next;
        current->next = nodo;
    }
    this->size++;
}

void LinkedList::print(){
    Node* current = this->head;
    while (current != nullptr)
    {
        current->print();
        current = current->next;
    }
}


