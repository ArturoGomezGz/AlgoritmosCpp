#include "Graph.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

// Detecta el número de vértices para decidir si usar lista o matriz
void casosPrueba(const string& nombreArchivo) {
    ifstream contador(nombreArchivo);
    if (!contador.is_open()) {
        cout << "Error al abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    string linea;
    getline(contador, linea); // Saltar la línea de descripción
    int numVertices;
    contador >> numVertices;
    contador.close();

    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    Graph grafo;

    // Si el número de vértices es 10 o menos, usar lista; si es mayor, usar matriz
    if (numVertices <= 10) {
        grafo.loadDirWeightedGraphList(archivo);
    } else {
        grafo.loadDirWeightedGraphMatrix(archivo);
    }

    grafo.DFS(1);
    grafo.BFS(1);

    archivo.close();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " <archivo.txt>\n";
        return 1;
    }

    string filename = argv[1];
    casosPrueba(filename);

    return 0;
}
