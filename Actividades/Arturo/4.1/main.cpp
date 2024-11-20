#include "MyGraph.h"

int main() {
    // Caso 1:
    vector<vector<int>> matriz1 = {
        {0, 1, 1, 0}, // Nodo 0
        {1, 0, 0, 1}, // Nodo 1
        {1, 0, 0, 0}, // Nodo 2
        {0, 1, 0, 0}  // Nodo 3
    };

    cout << "Caso 1: Grafo simple\n";
    MyGraph grafo1 = MyGraph(matriz1);
    cout << "Imprimiendo grafo:\n";
    grafo1.print();

    cout << "\nRecorrido DFS desde el nodo 0:\n";
    grafo1.DFS(0);

    cout << "\nRecorrido BFS desde el nodo 0:\n";
    grafo1.BFS(0);
    cout << "-----------------------------------------\n";

    // Caso 2:
    vector<vector<int>> matriz2 = {
        {0, 1, 1, 1, 0, 0}, // Nodo 0
        {1, 0, 0, 0, 1, 0}, // Nodo 1
        {1, 0, 0, 0, 0, 0}, // Nodo 2
        {1, 0, 0, 0, 0, 0}, // Nodo 3
        {0, 1, 0, 0, 0, 1}, // Nodo 4
        {0, 0, 0, 0, 1, 0}  // Nodo 5
    };

    cout << "Caso 2: Grafo 6x6 con mezcla de conexiones\n";
    MyGraph grafo6 = MyGraph(matriz2);
    cout << "Imprimiendo grafo:\n";
    grafo6.print();

    cout << "\nRecorrido DFS desde el nodo 0:\n";
    grafo6.DFS(0);

    cout << "\nRecorrido BFS desde el nodo 0:\n";
    grafo6.BFS(0);
    cout << "-----------------------------------------\n";

    return 0;
}
