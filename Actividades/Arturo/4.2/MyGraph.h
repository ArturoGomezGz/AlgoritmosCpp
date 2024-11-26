#ifndef MYGRAPH_H
#define MYGRAPH_H
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int id;
    int noNeighbors;
    vector<Node*> neighbors;

    // Constructor del nodo que inicializa su id y lista de vecinos
    // Complejidad: O(c)
    Node(int id, vector<Node*> neighbors)
    {
        this->id = id;
        this->neighbors = neighbors;
        this->noNeighbors = this->neighbors.size();
    }

    // Imprime el id del nodo
    // Complejidad: O(c)
    void print()
    {
        cout << "-" << this->id;
    }
};

class MyGraph
{
private:
    vector<Node*> nodes;
    vector<vector<int>> matriz;
    int size;
    int puentes;
public:
    // Constructor que inicializa el grafo con una matriz de adyacencia
    MyGraph(vector<vector<int>>& matriz);

    // Destructor del grafo
    ~MyGraph();

    // Carga el grafo a partir de la matriz de adyacencia
    void loadGraph(vector<vector<int>>& matriz);

    // Imprime el grafo mostrando los nodos y sus vecinos
    void print();

    // Inicia el recorrido DFS desde un nodo
    void DFS(int nodeIndex);

    // Realiza el recorrido DFS usando recursion
    void DFS(int nodeIndex, vector<bool>& visitados);

    // Inicia el recorrido BFS desde un nodo
    void BFS(int nodeIndex);

    // Is tree
    bool isTree();

};

#endif
