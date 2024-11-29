#ifndef MYGRAPH_H
#define MYGRAPH_H
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Estructura para representar un nodo
struct Node
{
    int id;
    int noNeighbors;
    vector<Node*> neighbors;

    // Constructor del nodo que inicializa su id y lista de vecinos
    Node(int id, vector<Node*> neighbors)
    {
        this->id = id;
        this->neighbors = neighbors;
        this->noNeighbors = this->neighbors.size();
    }

    // Imprime el id del nodo
    void print()
    {
        cout << "-" << this->id;
    }
};

class MyGraph
{
private:
    vector<Node*> nodes; // Lista de nodos en el grafo
    vector<vector<int>> matriz; // Matriz de adyacencia
    int size; // Cantidad de nodos
    int puentes; // Cantidad de arcos
    bool tieneCiclos(int nodeIndex, vector<bool>& visitados, vector<bool>& enCamino); // Verifica si el grafo tiene ciclos

public:
    // Constructor que inicializa el grafo con una matriz de adyacencia
    MyGraph(vector<vector<int>>& matriz);

    // Destructor del grafo
    ~MyGraph();

    // Carga el grafo a partir de la matriz de adyacencia
    void loadGraph();

    // Imprime el grafo mostrando los nodos y sus vecinos
    void print();

    // Inicia el recorrido DFS desde un nodo
    void DFS(int nodeIndex);

    // Realiza el recorrido DFS usando recursion
    void DFS(int nodeIndex, vector<bool>& visitados);

    // Inicia el recorrido BFS desde un nodo
    void BFS(int nodeIndex);

    // Verifica si el grafo es un arbol
    bool isTree();

    // Imprime los nodos en orden topologico usando el algoritmo de Kahn
    void topologicalSort();

    // Determina si el grafo es bipartito
    bool bipartiteGraph();
};

#endif
