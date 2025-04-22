#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>

using namespace std;

template <typename T>
struct Node {
    // Constructor: Inicializa un nodo con el valor especificado
    // Complejidad: O(1)
    Node(T valor) : valor(valor) {}

    // Imprime el valor del nodo
    // Complejidad: O(1)
    void print() {
        cout << valor << " ";
    }

    T valor; // Valor del nodo
    Node<T>* left = nullptr; // Puntero al hijo izquierdo
    Node<T>* right = nullptr; // Puntero al hijo derecho
};

template <typename T>
class BST {
public:
    // Constructor: Inicializa un árbol vacío
    // Complejidad: O(1)
    BST();

    // Inserta un valor en el BST
    // Complejidad: O(h) donde h es la altura del árbol
    int insert(T valor);

    // Busca un valor en el BST
    // Complejidad: O(h) donde h es la altura del árbol
    bool search(T valor) const;

    // Verifica si el árbol está vacío
    // Complejidad: O(1)
    bool isEmpty() const;
    
    // Regresa la diferencia absoluta mínima entre cualquier par de nodos del BST
    // Complejidad: O(n) donde n es el número de nodos
    T minDifference();
    
    // Regresa un entero que indica el nivel en que se encuentra un dato, o -1 en caso de que no se encuentre en el BST
    // Complejidad: O(h) donde h es la altura del árbol
    int whatLevelAmI(T valor);
    
    // Muestra los ancestros de un dato en el BST
    // Complejidad: O(h) donde h es la altura del árbol
    void ancestors(T valor);

    // Dado un segundo BST recibido como parámetro, este método regresa un vector que contiene los datos
    // que se encuentran en ambos BST (la intersección).
    // Complejidad: O(n*log(m)) donde n es el tamaño del BST actual y m el tamaño del segundo BST
    vector<T> intersection(const BST<T>& otherBST);

private:
    Node<T>* root; // Raíz del árbol
    int size;      // Tamaño del árbol

    // Función auxiliar recursiva para insertar un nodo
    int insertRec(Node<T>* current, Node<T>* newNode);

    // Función auxiliar recursiva para buscar un valor
    bool searchRec(Node<T>* current, T valor) const;

    // Función auxiliar recursiva para encontrar y mostrar ancestros
    bool ancestorsRec(Node<T>* current, T valor);
    
    // Función auxiliar recursiva para encontrar el nivel de un dato
    int whatLevelAmIRec(Node<T>* current, T valor, int nivel);
    
    // Función auxiliar para almacenar los valores del BST en orden en un vector
    void storeInorder(Node<T>* current, vector<T>& values);
    
    // Función auxiliar para recorrer este árbol y encontrar elementos en común con otro BST
    void findIntersection(Node<T>* current, const BST<T>& otherBST, vector<T>& result) const;
};

#include "BST.cpp"

#endif // BST_H
