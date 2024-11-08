#include "BST.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Constructor complejidad O(1)
BST::BST(){
    this->root = nullptr;
    this->height = 0;
    this->size = 0;
}

// Destructor complejidad O(n)
BST::~BST() {
    clear(root);
}

// Método para liberar memoria de los nodos complejidad O(n)
void BST::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

// Método para verificar si el árbol está vacío complejidad O(1)
bool BST::isEmpty() {
    return root == nullptr;
}

// Método para obtener la longitud (cantidad de nodos) del árbol complejidad O(1)
int BST::length() {
    return size;
}

// Método para convertir una dirección IP a un valor comparable complejidad O(1)
long long BST::ipToComparableValue(string ipStr) {
    size_t colonPos = ipStr.find(':');
    if (colonPos != string::npos) {
        ipStr = ipStr.substr(0, colonPos);
    }

    stringstream ss(ipStr);
    string segment;
    long long result = 0;

    while (getline(ss, segment, '.')) {
        // Check if the segment is numeric
        if (!all_of(segment.begin(), segment.end(), ::isdigit)) {
            throw invalid_argument("Non-numeric IP segment: " + segment);
        }
        result = (result << 8) + stoi(segment);
    }

    return result;
}

// Método para buscar un valor en el árbol de forma iterativa complejidad O(log n)
bool BST::search(string val) {
    long long ipValue = this->ipToComparableValue(val);
    Node* current = root;

    while (current) {
        if (ipValue == current->ipComparableValue) {
            return true; // Encontrado
        } else if (ipValue < current->ipComparableValue) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false; // No encontrado
}

// Método de búsqueda recursiva que llama a la sobrecarga privada complejidad O(log n)
bool BST::searchRec(string val) {
    long long ipValue = this->ipToComparableValue(val); // Convertimos IP a un valor comparable
    return searchRec(ipValue, root);
}

// Método de búsqueda recursiva sobrecargado (privado) complejidad O(log n)
bool BST::searchRec(long long val, Node* current) {
    if (!current) {
        return false; // No encontrado
    }
    if (val == current->ipComparableValue) {
        return true; // Encontrado
    } else if (val < current->ipComparableValue) {
        return searchRec(val, current->left);
    } else {
        return searchRec(val, current->right);
    }
}

// Método para insertar un nuevo nodo con el valor especificado complejidad O(log n)
bool BST::insert(string val) {
    if (this->isEmpty()) {
        root = new Node(val);
        size++;
        return true;
    }

    // Llamada recursiva para insertar a partir del nodo raíz
    root = insert(root, val);
    size++;
    return true;
}

// Método de ayuda para insertar nodos de forma recursiva complejidad O(log n)
Node* BST::insert(Node* node, string val) {
    if (!node) {
        return new Node(val);
    }
    Node aux = Node(val);
    if (aux.ipComparableValue < node->ipComparableValue) {
        node->left = insert(node->left, val);
    } else {
        node->right = insert(node->right, val);
    }
    return node;
}

// Método para insertar nodos a partir de un archivo de texto complejidad O(n log n)
bool BST::insertFromTxt(string txtDoc){
    ifstream fileLine("./"+txtDoc+".txt");
    
    cout << "documento abierto con exito" << endl;

    string line;
    int totalFilas = 0;
    while (getline(fileLine, line))
    {
        totalFilas++;
        cout << totalFilas << endl;
    }

    ifstream file("./"+txtDoc+".txt");
    int contador = 0;
    // Procesa cada línea del archivo
    while (getline(file, line))
    {
        contador++;
        insert(line);
        cout << "Cargando Documento" << endl;
        cout << (contador*100)/totalFilas << "%" << endl;
        system("clear");
    }
    
    system("cls");
    system("clear");
    cout << "documento cargado con exito" << endl;

    file.close();
    return true;
}

// Método para imprimir el árbol en orden
void BST::print() {
    printInOrder(root);
}

// Método auxiliar para imprimir el árbol en orden (privado)
void BST::printInOrder(Node* node) {
    if (node!=nullptr) {
        printInOrder(node->left);
        node->print();
        printInOrder(node->right);
    }
}

void BST::writeInOrder(Node* node, ofstream& outFile) {
        if (node != nullptr) {
            writeInOrder(node->left, outFile);
            outFile << node->write() << endl;  // Escribe el contenido del nodo en el archivo
            writeInOrder(node->right, outFile);
        }
    }

void BST::writeToFile(const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        writeInOrder(root, outFile);
        outFile.close();
    } else {
        cerr << "No se pudo abrir el archivo." << endl;
    }
}

// Nota: La implementación de remove() queda pendiente, ya que requeriría un método específico para eliminar un nodo dado,
//       y es algo más complejo de implementar debido a los distintos casos (nodo con 0, 1 o 2 hijos).
