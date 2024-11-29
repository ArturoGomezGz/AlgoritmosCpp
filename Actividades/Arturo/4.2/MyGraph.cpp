#include "MyGraph.h"

// Constructor que inicializa el grafo con una matriz de adyacencia
// Complejidad: O(n^2)
MyGraph::MyGraph(vector<vector<int>>& matriz)
{
    this->size = matriz.size();
    this->nodes.resize(size);
    this->matriz = matriz;
    loadGraph();
}

// Destructor del grafo
// Complejidad: O(1)
MyGraph::~MyGraph() {}

// Carga el grafo a partir de la matriz de adyacencia
// Complejidad: O(n^2)
void MyGraph::loadGraph()
{
    this->puentes = 0;
    for (int i = 0; i < size; i++) {
        nodes[i] = new Node(i, {});
    }
    for (int i = 0; i < size; i++) {
        int vecinos = 0;
        for (int j = 0; j < size; j++) {
            if (this->matriz[i][j] == 1) {
                this->puentes++;
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
    for (int i = 0; i < this->size; i++) {
        cout << "Nodo " << nodes[i]->id << " con " << nodes[i]->noNeighbors << " vecino(s): ";
        for (int j = 0; j < nodes[i]->noNeighbors; j++) {
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
        for (int i = 0; i < this->nodes[currentIndex]->noNeighbors; i++) {
            int neighborIndex = this->nodes[currentIndex]->neighbors[i]->id;
            if (!visitados[neighborIndex]) {
                visitados[neighborIndex] = true;
                cola.push(neighborIndex);
            }
        }
    }
}

// Verifica si el grafo tiene ciclos
// Complejidad: O(n)
bool MyGraph::tieneCiclos(int nodeIndex, vector<bool>& visitados, vector<bool>& enCamino)
{
    visitados[nodeIndex] = true;
    enCamino[nodeIndex] = true;
    for (int i = 0; i < this->nodes[nodeIndex]->noNeighbors; i++) {
        int vecino = this->nodes[nodeIndex]->neighbors[i]->id;
        if (!visitados[vecino] && tieneCiclos(vecino, visitados, enCamino)) return true;
        if (enCamino[vecino]) return true;
    }
    enCamino[nodeIndex] = false;
    return false;
}

// Verifica si el grafo es un arbol
// Complejidad: O(n^2)
bool MyGraph::isTree()
{
    if (this->puentes != this->size - 1) return false;
    vector<bool> visitados(this->size, false);
    DFS(0, visitados);
    for (int i = 0; i < this->size; i++) {
        if (!visitados[i]) return false;
    }
    vector<bool> visitadosParaCiclos(this->size, false);
    vector<bool> enCamino(this->size, false);
    for (int i = 0; i < this->size; i++) {
        if (!visitadosParaCiclos[i]) {
            if (tieneCiclos(i, visitadosParaCiclos, enCamino)) return false;
        }
    }
    return true;
}

// Imprime los nodos en orden topologico usando el algoritmo de Kahn
// Complejidad: O(n^2)
void MyGraph::topologicalSort()
{
    vector<int> inDegree(this->size, 0);
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            if (this->matriz[i][j] == 1) {
                inDegree[j]++;
            }
        }
    }
    queue<int> q;
    for (int i = 0; i < this->size; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topologicalOrder;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        topologicalOrder.push_back(current);
        for (int j = 0; j < this->size; j++) {
            if (this->matriz[current][j] == 1) {
                inDegree[j]--;
                if (inDegree[j] == 0) {
                    q.push(j);
                }
            }
        }
    }
    if (topologicalOrder.size() != this->size) return;
    for (int i = 0; i < topologicalOrder.size(); i++) {
        cout << topologicalOrder[i];
        if (i < topologicalOrder.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
}

// Determina si el grafo es bipartito
// Complejidad: O(n + m) donde m es el numero de arcos
bool MyGraph::bipartiteGraph()
{
    vector<int> colores(this->size, -1);
    for (int inicio = 0; inicio < this->size; inicio++) {
        if (colores[inicio] == -1) {
            queue<int> q;
            q.push(inicio);
            colores[inicio] = 0;
            while (!q.empty()) {
                int nodoActual = q.front();
                q.pop();
                for (int j = 0; j < this->nodes[nodoActual]->noNeighbors; j++) {
                    int vecino = this->nodes[nodoActual]->neighbors[j]->id;
                    if (colores[vecino] == -1) {
                        colores[vecino] = 1 - colores[nodoActual];
                        q.push(vecino);
                    } else if (colores[vecino] == colores[nodoActual]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
