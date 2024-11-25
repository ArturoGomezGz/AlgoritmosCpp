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

    return 0;
}
