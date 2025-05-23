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
};

#endif // GRAPH_H
