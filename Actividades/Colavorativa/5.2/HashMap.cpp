#include "HashMap.h"

// Constructor: inicializa el HashMap con tamaño 0 y sin claves.
// Complejidad: O(1)
HashMap::HashMap() {
    this->size = 0;
    this->keys = nullptr;
}

// Retorna el tamaño actual del HashMap.
// Complejidad: O(1)
int HashMap::length() {
    return this->size;
}

// Verifica si el HashMap está vacío.
// Complejidad: O(1)
bool HashMap::isEmpty() {
    return this->size == 0;
}

// Inserta una nueva línea en el HashMap, asociándola a una IP.
// Complejidad: O(n)
void HashMap::insert(string line) {
    string ip = this->getIp(line);
    MapNode* current = this->keys;
    while (current != nullptr) {
        if (current->ip == ip) {
            current->insert(line);
            return;
        }
        current = current->next;
    }
    newIp(ip);
}

// Crea un nuevo nodo para una IP y lo agrega al HashMap en el lugar correspondiente.
// Complejidad: O(n)
void HashMap::newIp(string ip) {
    if (this->isEmpty()) {
        this->keys = new MapNode(ip);
    } else {
        MapNode* node = new MapNode(ip);
        MapNode* current = this->keys;
        while (current->next != nullptr && current->next->ipLong < node->ipLong) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
    this->size++;
}

// Imprime el contenido completo del HashMap.
// Complejidad: O(n)
void HashMap::print() {
    MapNode* current = keys;
    while (current != nullptr) {
        current->print();
        current = current->next;
    }
}

// Extrae la IP de una línea de texto.
// Complejidad: O(k)
string HashMap::getIp(string line) {
    istringstream iss(line);
    string word;
    int wordCount = 0;

    while (iss >> word) {
        wordCount++;
        if (wordCount == 4) {
            size_t colonPos = word.find(':');
            if (colonPos != string::npos) {
                return word.substr(0, colonPos);
            }
            return word;
        }
    }

    return "";
}

// Carga el contenido de un archivo de texto al HashMap.
// Complejidad: O(m * n)
void HashMap::loadTxt(string file) {
    ifstream fileLine("./" + file + ".txt");

    if (!fileLine.is_open()) {
        throw runtime_error("Could not open file");
    }

    string line;
    while (getline(fileLine, line)) {
        this->insert(line);
    }
    fileLine.close();
}
