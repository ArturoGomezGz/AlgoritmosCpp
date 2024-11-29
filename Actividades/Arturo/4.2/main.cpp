#include "MyGraph.h"

int main() {
    // Grafo 1: Un árbol (DAG válido y bipartito)
    vector<vector<int>> adjMatrixTree = {
        {0, 1, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    // Grafo 2: Grafo con ciclos (no es un árbol ni bipartito)
    vector<vector<int>> adjMatrixWithCycle = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0}
    };

    // Grafo 3: DAG que no es un árbol (es bipartito)
    vector<vector<int>> adjMatrixDAG = {
        {0, 1, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    // Creación de grafos
    MyGraph grafoTree(adjMatrixTree);
    MyGraph grafoWithCycle(adjMatrixWithCycle);
    MyGraph grafoDAG(adjMatrixDAG);

    // Pruebas con el primer grafo
    cout << "Grafo 1:" << endl;
    cout << "Es un árbol: " << (grafoTree.isTree() ? "Sí" : "No") << endl;
    cout << "Es bipartito: " << (grafoTree.bipartiteGraph() ? "Sí" : "No") << endl;
    cout << "Orden topológico: ";
    grafoTree.topologicalSort();
    cout << endl;

    // Pruebas con el segundo grafo
    cout << "Grafo 2:" << endl;
    cout << "Es un árbol: " << (grafoWithCycle.isTree() ? "Sí" : "No") << endl;
    cout << "Es bipartito: " << (grafoWithCycle.bipartiteGraph() ? "Sí" : "No") << endl;
    cout << "Orden topológico: ";
    grafoWithCycle.topologicalSort();
    cout << endl;

    // Pruebas con el tercer grafo
    cout << "Grafo 3:" << endl;
    cout << "Es un árbol: " << (grafoDAG.isTree() ? "Sí" : "No") << endl;
    cout << "Es bipartito: " << (grafoDAG.bipartiteGraph() ? "Sí" : "No") << endl;
    cout << "Orden topológico: ";
    grafoDAG.topologicalSort();
    cout << endl;

    return 0;
}
