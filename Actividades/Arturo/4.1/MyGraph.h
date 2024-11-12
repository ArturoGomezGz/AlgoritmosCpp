#ifndef MYGRAPH_H
#define MYGRAPH_H
#include <iostream>
#include <vector>

using namespace std;

class MyGraph
{
private:
    vector<vector<int>> matriz;
public:
    MyGraph(vector<vector<int>>& matriz);
    ~MyGraph();
    void loadGraph(vector<vector<int>>& matriz);
    void DFS();
    void BFS();
};

#endif