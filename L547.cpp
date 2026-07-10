#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void DFS(vector<vector<int>> &isConnected, vector<bool> &visited, int node)
  {
    visited[node] = true;
    for (int i = 0; i < isConnected.size(); i++)
    {
      if (isConnected[node][i] == 1 && !visited[i])
      {
        DFS(isConnected, visited, i);
      }
    }
    return;
  }

  int findCircleNum(vector<vector<int>> &isConnected)
  {
    int provinces = 0;
    vector<bool> visited(isConnected.size(), false);

    for (int i = 0; i < visited.size(); i++)
    {
      if (!visited[i])
      {
        // do a DFS on it..
        provinces++;
        DFS(isConnected, visited, i);
      }
    }
    return provinces;
  }
};