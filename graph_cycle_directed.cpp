#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  bool DFS(vector<vector<int>> &edges, vector<bool> &visited, int node, vector<bool> &pathVisited)
  {
    visited[node] = true;
    pathVisited[node] = true;
    for (int i = 0; i < edges.size(); i++)
    {
      if (edges[i][0] == node)
      {
        int neighbour = edges[i][1];
        if (visited[neighbour])
        {
          if (pathVisited[neighbour])
          {
            return true;
          }
        }
        else
        {
          bool res = DFS(edges, visited, neighbour, pathVisited);
          if (res)
          {
            return true;
          }
        }
      }
    }
    pathVisited[node] = false;
    return false;
  }

  bool isCyclic(int V, vector<vector<int>> &edges)
  {
    // code here
    vector<bool> visited(V, false);
    vector<bool> pathVisited(V, false);
    for (int i = 0; i < V; i++)
    {
      int node = i;

      if (!visited[node])
      {
        bool res = DFS(edges, visited, node, pathVisited);
        if (res)
        {
          return true;
        }
      }
    }
    return false;
  }
};