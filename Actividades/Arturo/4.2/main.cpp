#include "MyGraph.h"

int main() {
    // Caso 1:
    vector<vector<int>> adjMatrixNonTree = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };

    // Crear una matriz de adyacencia para un grafo que SÍ es un árbol
    vector<vector<int>> adjMatrixTree = {
        {0, 1, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    vector<vector<int>> adjMatrixNotTree = {
        {0, 1, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0}
    };

    MyGraph grafoTree = MyGraph(adjMatrixTree);
    MyGraph grafoNonTree = MyGraph(adjMatrixNotTree);
    /* cout << "Imprimiendo grafo:\n";
    grafoTree.print(); */


    if (grafoTree.isTree()){
        cout << "Es arbol" << endl;
    } else  {
        cout << "No es arbol" << endl;
    }

    if (grafoNonTree.isTree()){
        cout << "Es arbol" << endl;
    } else  {
        cout << "No es arbol" << endl;
    }

    return 0;
}
