#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Graph {
private:
    vector<list<pair<int, int>>> adjList;
    vector<vector<int>> adjMatrix;

    int numV;       // Número de vértices
    bool lOm;       // true = lista de adyacencia, false = matriz

    // DFS recursivo
    void DFSaux(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex + 1 << " "; // Imprimir en base 1

        if (lOm) {
            vector<pair<int, int>> vecinos(adjList[vertex].begin(), adjList[vertex].end());
            sort(vecinos.begin(), vecinos.end(), greater<pair<int, int>>());

            for (auto& vecino : vecinos) {
                if (!visited[vecino.first]) {
                    DFSaux(vecino.first, visited);
                }
            }
        } else {
            for (int i = 0; i < numV; i++) {
                if (adjMatrix[vertex][i] != 0 && !visited[i]) {
                    DFSaux(i, visited);
                }
            }
        }
    }

    // BFS usando cola
    void BFSaux(int vertex, vector<bool>& visited) {
        queue<int> q;
        visited[vertex] = true;
        q.push(vertex);

        while (!q.empty()) {
            int actual = q.front();
            q.pop();
            cout << actual + 1 << " ";

            if (lOm) {
                vector<pair<int, int>> vecinos(adjList[actual].begin(), adjList[actual].end());
                sort(vecinos.begin(), vecinos.end());

                for (auto& vecino : vecinos) {
                    if (!visited[vecino.first]) {
                        visited[vecino.first] = true;
                        q.push(vecino.first);
                    }
                }
            } else {
                for (int i = 0; i < numV; i++) {
                    if (adjMatrix[actual][i] != 0 && !visited[i]) {
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
        }
    }

    // Función auxiliar para verificar si un grafo es bipartito usando DFS
    bool isBipartiteAux(int start, vector<int>& colors) {
        // Cola para BFS
        queue<int> q;
        q.push(start);
        colors[start] = 1; // Asignar color 1 al nodo inicial
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            // Revisar todos los vecinos del nodo actual
            if (lOm) { // Lista de adyacencia
                for (auto& neighbor : adjList[current]) {
                    int v = neighbor.first;
                    
                    // Si el vecino no está coloreado
                    if (colors[v] == 0) {
                        // Asignar color opuesto al vecino
                        colors[v] = -colors[current];
                        q.push(v);
                    } 
                    // Si el vecino ya tiene color y es el mismo que el nodo actual
                    else if (colors[v] == colors[current]) {
                        return false; // No es bipartito
                    }
                }
            } else { // Matriz de adyacencia
                for (int v = 0; v < numV; v++) {
                    if (adjMatrix[current][v] != 0) { // Existe una arista
                        // Si el vecino no está coloreado
                        if (colors[v] == 0) {
                            // Asignar color opuesto al vecino
                            colors[v] = -colors[current];
                            q.push(v);
                        } 
                        // Si el vecino ya tiene color y es el mismo que el nodo actual
                        else if (colors[v] == colors[current]) {
                            return false; // No es bipartito
                        }
                    }
                }
            }
        }
        
        return true; // Si no hay conflictos, es bipartito
    }

public:
    Graph() : numV(0), lOm(true) {}

    // Cargar grafo desde archivo (lista de adyacencia)
    void loadDirWeightedGraphList(istream& input) {
        adjList.clear();

        string line;
        getline(input, line); // Saltar primera línea

        input >> numV;
        int numE;
        input >> numE;

        for (int i = 0; i < numV; i++) {
            getline(input, line);
            if (line.empty()) getline(input, line);
        }

        adjList.resize(numV);

        int from, to, weight;
        while (input >> from >> to >> weight) {
            adjList[from - 1].push_back({to - 1, weight});
        }

        for (auto& lista : adjList) {
            lista.sort([](const pair<int, int>& a, const pair<int, int>& b) {
                return a.first < b.first;
            });
        }

        lOm = true;
    }

    // Cargar grafo desde archivo (matriz de adyacencia)
    void loadDirWeightedGraphMatrix(istream& input) {
        adjMatrix.clear();

        string line;
        getline(input, line); // Saltar primera línea

        input >> numV;
        int numE;
        input >> numE;

        for (int i = 0; i < numV; i++) {
            getline(input, line);
            if (line.empty()) getline(input, line);
        }

        adjMatrix.resize(numV, vector<int>(numV, 0));

        int from, to, weight;
        while (input >> from >> to >> weight) {
            adjMatrix[from - 1][to - 1] = weight;
        }

        lOm = false;
    }

    // Recorrido en profundidad (DFS)
    void DFS(int startVertex) {
        startVertex--;

        vector<bool> visited(numV, false);
        cout << "Recorrido DFS\n";
        DFSaux(startVertex, visited);
        cout << endl;
    }

    // Recorrido en anchura (BFS)
    void BFS(int startVertex) {
        startVertex--;

        vector<bool> visited(numV, false);
        cout << "Recorrido BFS\n";
        BFSaux(startVertex, visited);
        cout << endl;
    }

    // Encuentra el camino más corto desde el vértice de origen a todos los demás
    void shortestPath(int startVertex) {
        startVertex--; // Convertir a base 0
        
        // Vector de distancias, inicializado con infinito
        vector<int> dist(numV, INT_MAX);
        // Vector de predecesores
        vector<int> prev(numV, -1);
        // Vector para marcar nodos visitados
        vector<bool> visited(numV, false);
        
        // Distancia a sí mismo es 0
        dist[startVertex] = 0;
        
        // Implementación de Dijkstra
        for (int count = 0; count < numV - 1; count++) {
            // Encontrar el vértice con la distancia mínima
            int u = -1;
            int minDist = INT_MAX;
            for (int v = 0; v < numV; v++) {
                if (!visited[v] && dist[v] <= minDist) {
                    minDist = dist[v];
                    u = v;
                }
            }
            
            // Si no se encontró un vértice válido (grafo desconectado)
            if (u == -1) break;
            
            visited[u] = true;
            
            // Actualizar distancias de los vértices adyacentes
            if (lOm) { // Lista de adyacencia
                for (auto& vecino : adjList[u]) {
                    int v = vecino.first;
                    int weight = vecino.second;
                    
                    if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                        prev[v] = u;
                    }
                }
            } else { // Matriz de adyacencia
                for (int v = 0; v < numV; v++) {
                    if (adjMatrix[u][v] != 0) {
                        int weight = adjMatrix[u][v];
                        
                        if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                            dist[v] = dist[u] + weight;
                            prev[v] = u;
                        }
                    }
                }
            }
        }
        
        // Imprimir resultados
        cout << "Vertex Distance from Source (" << startVertex + 1 << ")" << endl;
        for (int i = 0; i < numV; i++) {
            cout << i + 1 << "\t";
            if (dist[i] == INT_MAX)
                cout << "INF";
            else
                cout << dist[i];
            cout << endl;
        }
        
        cout << "\nShortest paths (predecessors):" << endl;
        for (int i = 0; i < numV; i++) {
            cout << i + 1 << "\t";
            if (prev[i] == -1 && i != startVertex)
                cout << "No path";
            else if (i == startVertex)
                cout << "Source";
            else
                cout << prev[i] + 1;
            cout << endl;
        }
    }

    // Determinar si el grafo es bipartito
    bool isBipartite() {
        // Vector para almacenar colores (0 = no asignado, 1 = color1, -1 = color2)
        vector<int> colors(numV, 0);
        
        // Para manejar grafos desconectados, verificamos cada componente
        for (int i = 0; i < numV; i++) {
            if (colors[i] == 0) { // Si el nodo no ha sido coloreado
                if (!isBipartiteAux(i, colors)) {
                    return false;
                }
            }
        }
        
        return true; // Todas las componentes son bipartitas
    }
};

#endif // GRAPH_H
