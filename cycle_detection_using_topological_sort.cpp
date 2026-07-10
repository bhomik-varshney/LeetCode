#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
  bool isCyclic(int V, vector<vector<int>> &edges)
  {
    queue<int> q;
    vector<int> indegree(V);
    vector<vector<int>> adj(V);
    vector<int> topoSort;
    for (int i = 0; i < edges.size(); i++)
    {
      int src = edges[i][0];
      int des = edges[i][1];

      adj[src].push_back(des);
      indegree[des]++;
    }

    for (int i = 0; i < indegree.size(); i++)
    {
      if (indegree[i] == 0)
      {
        q.push(i);
      }
    }

    while (!q.empty())
    {
      int node = q.front();
      topoSort.push_back(node);
      for (int i = 0; i < adj[node].size(); i++)
      {
        int neighbour = adj[node][i];

        indegree[neighbour]--;
        if (indegree[neighbour] == 0)
        {
          q.push(neighbour);
        }
      }
      q.pop();
    }

    if (topoSort.size() == V)
    {
      return false;
    }
    else
    {
      return true;
    }
  }
};