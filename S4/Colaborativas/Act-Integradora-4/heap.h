#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <string>
#include <vector>
#include "Node.h"

using namespace std;

class heap {
private:
    vector<Node*> data;
    int size;

    // Helper functions
    void heapifyUp(int index);
    void heapifyDown(int index);
    int parent(int index) { return (index - 1) / 2; }
    int leftChild(int index) { return 2 * index + 1; }
    int rightChild(int index) { return 2 * index + 2; }
    
    // Compare function for max heap ordering (based on Node's grado)
    bool compare(Node* a, Node* b) {
        return a->grado > b->grado; // Always max heap comparison
    }

public:
    // Constructor
    heap() : size(0) {}
    
    // Destructor
    ~heap() {
        // Note: This doesn't delete the Node objects, just clears the vector
        data.clear();
    }
    
    // Core heap operations
    void insert(Node* node);
    Node* extractTop(); // Returns and removes the root node
    Node* peekTop(); // Returns the root node without removing it
    
    // Utility methods
    bool isEmpty() { return size == 0; }
    int getSize() { return size; }
    void print();
};

// Implementation of heap methods

void heap::heapifyUp(int index) {
    if (index == 0) return; // Root reached
    
    int p = parent(index);
    if (compare(data[index], data[p])) {
        swap(data[index], data[p]);
        heapifyUp(p);
    }
}

void heap::heapifyDown(int index) {
    int largest = index;
    int left = leftChild(index);
    int right = rightChild(index);
    
    if (left < size && compare(data[left], data[largest])) {
        largest = left;
    }
    
    if (right < size && compare(data[right], data[largest])) {
        largest = right;
    }
    
    if (largest != index) {
        swap(data[index], data[largest]);
        heapifyDown(largest);
    }
}

void heap::insert(Node* node) {
    data.push_back(node);
    size++;
    heapifyUp(size - 1);
}

Node* heap::extractTop() {
    if (isEmpty()) {
        return nullptr;
    }
    
    Node* top = data[0];
    data[0] = data[size - 1];
    data.pop_back();
    size--;
    
    if (size > 0) {
        heapifyDown(0);
    }
    
    return top;
}

Node* heap::peekTop() {
    if (isEmpty()) {
        return nullptr;
    }
    return data[0];
}

void heap::print() {
    cout << "Heap contenido (Max-Heap):" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Indice " << i << ": IP=" << data[i]->ip.ipNoPrt 
             << ", Grado=" << data[i]->grado << endl;
    }
}

#endif //HEAP_H
