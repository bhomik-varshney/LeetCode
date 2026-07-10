#include <iostream>
using namespace std;

class Solution
{
public:
  vector<vector<int>> printGraph(int V, vector<pair<int, int>> &edges)
  {
    // code here
    vector<vector<int>> adjList(V);
    // 0 is the index for that...
    for (auto i : edges)
    {
      int v1 = i.first;
      int v2 = i.second;

      adjList[v1].push_back(v2);
      adjList[v2].push_back(v1); // for undirected graph
    }
    return adjList;
  }
};