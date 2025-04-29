#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
private:
    int* heap;
    int capacity;
    int size;

    // Mueve un elemento hacia arriba para mantener la propiedad del heap
    // O(log n)
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        if (index > 0 && heap[parent] < heap[index]) {
            swap(heap[parent], heap[index]);
            heapifyUp(parent);
        }
    }

    // Mueve un elemento hacia abajo para mantener la propiedad del heap
    // O(log n)
    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Construye un MaxHeap a partir de un array mediante heapify
    // O(n)
    MaxHeap(const vector<int>& arr) {
        capacity = arr.size();
        size = arr.size();
        heap = new int[capacity];
        
        for (int i = 0; i < size; i++) {
            heap[i] = arr[i];
        }
        
        for (int i = (size / 2) - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    // Añade un nuevo valor al heap
    // O(log n)
    void push(int value) {
        if (size == capacity) {
            cout << "Heap is full" << endl;
            return;
        }
        heap[size] = value;
        size++;
        heapifyUp(size - 1);
    }

    // Elimina y devuelve el elemento máximo del heap
    // O(log n)
    int pop() {
        if (size == 0) {
            cout << "Heap is empty" << endl;
            return -1;
        }
        int maxValue = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return maxValue;
    }

    // Devuelve el elemento máximo sin eliminarlo
    // O(1) 
    int top() {
        if (size == 0) {
            cout << "Heap is empty" << endl;
            return -1;
        }
        return heap[0];
    }

    // Verifica si el heap está vacío
    // O(1) 
    bool empty() {
        return size == 0;
    }

    // Devuelve el número actual de elementos en el heap
    // O(1) 
    int getCurrentSize() {
        return size;
    }

    // Combina otro heap con este
    // O(m log n)
    void mezclar(const MaxHeap& heap2) {
        MaxHeap tempHeap = heap2;
        while (!tempHeap.empty()) {
            push(tempHeap.pop());
        }
    }
};
