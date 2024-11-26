#include "MyGraph.h"

// Constructor que inicializa el grafo con una matriz de adyacencia
// Complejidad: O(n^2)
MyGraph::MyGraph(vector<vector<int>>& matriz)
{
    this->size = matriz.size();
    this->nodes.resize(size);
    this->matriz = matriz;
    loadGraph(this->matriz);
}

MyGraph::~MyGraph()
{
}

// Carga el grafo a partir de la matriz de adyacencia
// Complejidad: O(n^2)
void MyGraph::loadGraph(vector<vector<int>>& matriz)
{
    for (int i = 0; i < size; i++)
    {
        nodes[i] = new Node(i, {});
    }

    for (int i = 0; i < size; i++)
    {
        int vecinos = 0;
        for (int j = 0; j < size; j++)
        {
            if (matriz[i][j] == 1)
            {
                vecinos++;
                nodes[i]->neighbors.push_back(nodes[j]);
            }
        }
        nodes[i]->noNeighbors = vecinos;
    }
}

// Imprime el grafo mostrando los nodos y sus vecinos
// Complejidad: O(n^2)
void MyGraph::print()
{
    for (int i = 0; i < this->size; i++)
    {
        cout << "Nodo " << nodes[i]->id << " con " << nodes[i]->noNeighbors << " vecino(s): ";
        for (int j = 0; j < nodes[i]->noNeighbors; j++)
        {
            nodes[i]->neighbors[j]->print();
        }
        cout << endl;
    }
}

// Inicia el recorrido DFS desde un nodo
// Complejidad: O(n)
void MyGraph::DFS(int nodeIndex)
{
    vector<bool> visitados(this->nodes.size(), false);
    DFS(nodeIndex, visitados);
}

// Realiza el recorrido DFS usando recursion
// Complejidad: O(n)
void MyGraph::DFS(int nodeIndex, vector<bool>& visitados)
{
    visitados[nodeIndex] = true;

    cout << "Visited Node: " << this->nodes[nodeIndex]->id << endl;

    for (int i = 0; i < this->nodes[nodeIndex]->noNeighbors; i++) {
        int neighborIndex = this->nodes[nodeIndex]->neighbors[i]->id;

        if (!visitados[neighborIndex]) {
            DFS(neighborIndex, visitados);
        }
    }
}

// Inicia el recorrido BFS desde un nodo
// Complejidad: O(n)
void MyGraph::BFS(int nodeIndex)
{
    vector<bool> visitados(this->nodes.size(), false);

    queue<int> cola;

    visitados[nodeIndex] = true;
    cola.push(nodeIndex);

    while (!cola.empty()) {
        int currentIndex = cola.front();
        cola.pop();

        cout << "Visited Node: " << this->nodes[currentIndex]->id << endl;

        for (int i = 0; i < this->nodes[currentIndex]->noNeighbors; i++) {
            int neighborIndex = this->nodes[currentIndex]->neighbors[i]->id;

            if (!visitados[neighborIndex]) {
                visitados[neighborIndex] = true;
                cola.push(neighborIndex);
            }
        }
    }
}


