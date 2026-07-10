#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> findIndegree(int V, vector<vector<int>> &edges)
  {
    vector<int> res(V, 0);

    for (int i = 0; i < edges.size(); i++)
    {
      int src = edges[i][0];
      int des = edges[i][1];

      res[des]++;
    }

    return res;
  }

  int findMinIndegree(vector<int> &indegree, vector<bool> &visited)
  {
    int node = -1;
    int minIndegree = INT_MAX;
    for (int i = 0; i < indegree.size(); i++)
    {
      if (indegree[i] < minIndegree && !visited[i])
      {
        minIndegree = indegree[i];
        node = i;
      }
    }
    return node;
  }

  vector<int> topoSort(int V, vector<vector<int>> &edges)
  {
    // code here
    // find the indegree for each vertex...
    vector<int> res;
    vector<bool> visited(V, false);
    vector<int> indegree = findIndegree(V, edges); // O(E)

    // make adj list
    vector<vector<int>> adj(V);
    for (int i = 0; i < edges.size(); i++)
    {
      int src = edges[i][0];
      int des = edges[i][1];

      adj[src].push_back(des);
    }

    int node = findMinIndegree(indegree, visited);
    while (node != -1)
    {
      res.push_back(node);
      visited[node] = true;
      for (int i = 0; i < adj[node].size(); i++)
      {
        int des = adj[node][i];
        indegree[des]--;
      }

      node = findMinIndegree(indegree, visited);
    }
    return res;
  }
};