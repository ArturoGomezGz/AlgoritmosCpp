#ifndef BST_H
#define BST_H
#include <fstream>
#include "node.h"

class BST
{
private:
    Node* root;
    int height;
    int size;

    // Método auxiliar para búsqueda recursiva
    bool searchRec(long long val, Node* current);

    // Método auxiliar para inserción recursiva
    Node* insert(Node* node, string val);

    // Método auxiliar para liberar memoria
    void clear(Node* node);

    // Método auxiliar para impresión en orden
    void printInOrder(Node* node);

    // Método auxiliar para escritura en orden
    void writeInOrder(Node* node, ofstream& outFile);

    // Método auxiliar para convertir una IP a un valor comparable
    long long ipToComparableValue(string ipStr);

public:
    BST();
    ~BST();

    void print();
    int length();
    bool isEmpty();
    bool search(string val);
    bool searchRec(string val);
    bool insert(string val);
    bool insertFromTxt(string txtDoc);
    void writeToFile(const string& filename);
    bool remove();
};

#endif