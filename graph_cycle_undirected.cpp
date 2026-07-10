#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  bool DFS(vector<vector<int>> &edges, int node, vector<bool> &visited, vector<int> &parent)
  {
    visited[node] = true;
    vector<bool> verdict;
    for (int i = 0; i < edges.size(); i++)
    {
      if (edges[i][0] == node || edges[i][1] == node)
      {
        if (edges[i][0] == node)
        {
          int neighbour = edges[i][1];
          if (parent[node] == neighbour)
          {
            continue;
          }
          else
          {
            if (visited[neighbour])
            {
              return true;
            }
            else
            {
              parent[neighbour] = node;
              verdict.push_back(DFS(edges, neighbour, visited, parent));
            }
          }
        }
        else
        {
          int neighbour = edges[i][0];
          if (parent[node] == neighbour)
          {
            continue;
          }
          else
          {
            if (visited[neighbour])
            {
              return true;
            }
            else
            {
              parent[neighbour] = node;
              verdict.push_back(DFS(edges, neighbour, visited, parent));
            }
          }
        }
      }
    }

    for (int i = 0; i < verdict.size(); i++)
    {
      if (verdict[i] == true)
      {
        return true;
      }
    }
    return false;
  }

  bool isCycle(int V, vector<vector<int>> &edges)
  {
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);
    for (int i = 0; i < V; i++)
    {
      int node = i;
      if (!visited[node])
      {
        bool res = DFS(edges, node, visited, parent);
        if (res)
        {
          return true;
        }
      }
    }
    return false;
  }
};