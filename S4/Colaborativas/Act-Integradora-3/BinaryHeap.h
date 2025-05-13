#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <utility>
#include <climits>

#include "Node.h"

class BinaryHeap
{
public:
    // Constructor por defecto para inicializar un heap vacío
    // Complejidad temporal: O(1)
    BinaryHeap();
    
    // Destructor que libera la memoria de todos los nodos del heap
    // Complejidad temporal: O(n) donde n es el número de nodos
    ~BinaryHeap();

    // Inserta un nuevo valor en el heap manteniendo la propiedad de heap
    // Complejidad temporal: O(log n) donde n es el número de elementos en el heap
    void insert(string nodeValue);
    
    // Mantiene la propiedad de heap a partir de un nodo específico hacia abajo
    // Complejidad temporal: O(log n) en el peor caso
    void heapify(int index);
    
    // Construye un heap a partir de un arreglo desordenado
    // Complejidad temporal: O(n) donde n es el número de elementos
    void buildHeap();
    
    // Ordena los elementos del heap utilizando el algoritmo heapsort
    // Complejidad temporal: O(n log n)
    void heapSort();
    
    // Lee direcciones IP desde un archivo y las inserta en el heap
    // Complejidad temporal: O(n log n) donde n es el número de líneas en el archivo
    void readFromFile(string filename);
    
    // Escribe los valores del heap en un archivo
    // Complejidad temporal: O(n) donde n es el número de elementos en el heap
    void writeToFile(string filename);
    
    // Cuenta el número de accesos por cada dirección IP
    // Complejidad temporal: O(n) donde n es el número de elementos en el heap
    void countIpAccesses();
    
    // Encuentra las n direcciones IP con mayor número de accesos
    // Complejidad temporal: O(m log m) donde m es el número de IPs únicas
    void findTopIpsByAccess(int n);
    
    // Escribe en un archivo las n direcciones IP con mayor número de accesos
    // Complejidad temporal: O(m log m) donde m es el número de IPs únicas
    void writeTopIpsToFile(string filename, int n);
    
    // Encuentra la dirección IP con menor recurrencia que supere un umbral dado
    // Complejidad temporal: O(m) donde m es el número de IPs únicas
    pair<string, int> findLeastRecurringIpAboveThreshold(int threshold);

private:
    vector<Node*> heap;
    map<string, int> ipAccessCount;
    
    // Intercambia dos elementos del heap
    // Complejidad temporal: O(1)
    void swap(int i, int j);
};

BinaryHeap::BinaryHeap() {
    // Constructor por defecto vacio
}

BinaryHeap::~BinaryHeap() {
    // Destructor que libera la memoria de todos los nodos del heap
    for (auto node : heap) {
        delete node;
    }
    heap.clear();
}

void BinaryHeap::insert(string nodeValue) {
    // Crear un nuevo nodo con el valor dado
    Node* newNode = new Node(nodeValue);
    
    // Insertar el nuevo nodo al final del heap
    heap.push_back(newNode);
    
    int i = heap.size() - 1;
    int parent = (i - 1) / 2;
    
    // Reorganizar el heap hacia arriba
    while (i > 0 && heap[parent]->ip.ipComparableValue > heap[i]->ip.ipComparableValue) {
        swap(i, parent);
        i = parent;
        parent = (i - 1) / 2;
    }
}

void BinaryHeap::heapify(int index) {
    int size = heap.size();
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    // Comparar el nodo actual con sus hijos
    if (left < size && heap[left]->ip.ipComparableValue < heap[smallest]->ip.ipComparableValue)
        smallest = left;
    
    // Comparar el nodo más pequeño con su hijo derecho
    if (right < size && heap[right]->ip.ipComparableValue < heap[smallest]->ip.ipComparableValue)
        smallest = right;
    
    // Si el nodo más pequeño no es el nodo actual, intercambiarlos
    if (smallest != index) {
        swap(index, smallest);
        heapify(smallest);
    }
}

void BinaryHeap::buildHeap() {
    // Construir el heap desde el último nodo padre hacia arriba
    int size = heap.size();
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(i);
    }
}

void BinaryHeap::heapSort() {
    buildHeap();
    
    int size = heap.size();
    vector<Node*> sorted;
    
    for (int i = 0; i < size; i++) {
        sorted.push_back(heap[0]);
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapify(0);
        }
    }
    
    heap = sorted;
}

void BinaryHeap::readFromFile(string filename) {
    // Leer direcciones IP desde un archivo y construir el heap
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }
    
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            insert(line);
        }
    }
    
    file.close();
}

void BinaryHeap::writeToFile(string filename) {
    // Escribir los valores del heap en un archivo
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }
    
    for (auto node : heap) {
        file << node->value << endl;
    }
    
    file.close();
}

void BinaryHeap::swap(int i, int j) {
    Node* temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void BinaryHeap::countIpAccesses() {
    ipAccessCount.clear();
    
    for (auto node : heap) {
        string ipWithoutPort = node->ip.ip.substr(0, node->ip.ip.find(':'));
        ipAccessCount[ipWithoutPort]++;
    }
    
    cout << "Counted accesses for " << ipAccessCount.size() << " unique IP addresses." << endl;
}

void BinaryHeap::findTopIpsByAccess(int n) {
    if (ipAccessCount.empty()) {
        countIpAccesses();
    }
    
    priority_queue<pair<int, string>> pq;
    
    for (const auto& entry : ipAccessCount) {
        pq.push(make_pair(entry.second, entry.first));
    }
    
    cout << "\nTop " << n << " IPs by access count:" << endl;
    cout << "----------------------------" << endl;
    
    int count = 0;
    while (!pq.empty() && count < n) {
        auto top = pq.top();
        pq.pop();
        cout << top.second << " - " << top.first << " accesses" << endl;
        count++;
    }
}

void BinaryHeap::writeTopIpsToFile(string filename, int n) {
    if (ipAccessCount.empty()) {
        countIpAccesses();
    }
    
    priority_queue<pair<int, string>> pq;
    for (const auto& entry : ipAccessCount) {
        pq.push(make_pair(entry.second, entry.first));
    }
    
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }
    
    int count = 0;
    while (!pq.empty() && count < n) {
        auto top = pq.top();
        pq.pop();
        file << top.second << " - " << top.first << " accesses" << endl;
        count++;
    }
    
    file.close();
    cout << "Top " << n << " IPs written to " << filename << endl;
}

pair<string, int> BinaryHeap::findLeastRecurringIpAboveThreshold(int threshold) {
    if (ipAccessCount.empty()) {
        countIpAccesses();
    }
    
    string leastRecurringIp = "";
    int minCount = INT_MAX;
    
    for (const auto& entry : ipAccessCount) {
        if (entry.second >= threshold && entry.second < minCount) {
            minCount = entry.second;
            leastRecurringIp = entry.first;
        }
    }
    
    if (leastRecurringIp.empty()) {
        cout << "No IP found with access count >= " << threshold << endl;
        return make_pair("", 0);
    }
    
    cout << "\nIP with least recurrence >= " << threshold << " accesses: " 
         << leastRecurringIp << " - " << minCount << " accesses" << endl;
    
    return make_pair(leastRecurringIp, minCount);
}
