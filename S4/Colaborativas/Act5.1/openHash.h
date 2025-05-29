#ifndef OPENHASH_H
#define OPENHASH_H

#include <iostream>
#include <vector>
#include <list>
#include <functional>

using namespace std;

// Estructura de nodo que almacena pares clave-valor
template <typename K, typename T>
struct Node {
    K key;
    T value;
    
    Node(K k, T v) : key(k), value(v) {}
};

template <typename K, typename T>
class OpenHash {
private:
    vector<list<Node<K, T>>> table;  
    int size;                  
    
    int hashFunction(K key) {
        return hash<K>{}(key) % size;
    }
    
public:
    // Constructor que inicializa la tabla hash con un tamaño especificado
    // Complejidad: O(n) donde n es el tamaño de la tabla
    OpenHash(int tableSize = 10) {
        size = tableSize;
        table.resize(size);
    }
    
    // Añade un par clave-valor a la tabla hash o actualiza el valor si la clave ya existe
    // Complejidad: O(m) donde m es la longitud de la lista en el índice hash
    void add(K keyVal, T value) {
        int index = hashFunction(keyVal);
        
        for (auto& node : table[index]) {
            if (node.key == keyVal) {
                node.value = value; 
                return;
            }
        }
        
        table[index].push_back(Node(keyVal, value));
    }
    
    T find(K keyVal) {
        int index = hashFunction(keyVal);
        
        for (auto& node : table[index]) {
            if (node.key == keyVal) {
                return node.value;
            }
        }
        
        throw runtime_error("Key not found");
    }
    
    void remove(K keyVal) {
        int index = hashFunction(keyVal);
        
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == keyVal) {
                bucket.erase(it);
                return;
            }
        }
        
        throw runtime_error("Key not found");
    }
    
    void print() {
        for (int i = 0; i < size; i++) {
            cout << "Bucket " << i << ": ";
            
            if (table[i].empty()) {
                cout << "Empty";
            } else {
                for (auto& node : table[i]) {
                    cout << "[" << node.key << ":" << node.value << "] ";
                }
            }
            
            cout << endl;
        }
    }
};

#endif //OPENHASH_H
