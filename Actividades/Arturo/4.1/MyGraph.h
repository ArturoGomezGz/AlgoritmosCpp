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

    Node(int id, vector<Node*> neighbors)
    {
        this->id = id;
        this->neighbors = neighbors;
        this->noNeighbors = this->neighbors.size();
    }
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
public:
    MyGraph(vector<vector<int>>& matriz);
    ~MyGraph();
    void loadGraph(vector<vector<int>>& matriz);
    void print();
    void DFS(int nodeIndex);
    void DFS(int nodeIndex, vector<bool>& visitados);
    void BFS(int nodeIndex);
};

#endif