#include <iostream>
#include <vector>
using namespace std;

struct cmp
{
  bool operator()(pair<int, int> &a, pair<int, int> &b)
  {
    if (a.second > b.second)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

class Solution
{
public:
  int spanningTree(int V, vector<vector<int>> &edges)
  {
    // code here
    int res = 0;
    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < edges.size(); i++)
    {
      int u = edges[i][0];
      int v = edges[i][1];
      int w = edges[i][2];
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }

    // now our adjacency list is ready.....
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> heap; // min heap
    vector<int> dis(V, INT_MAX);
    vector<bool> visited(V, false);
    heap.push({0, 0});
    while (!heap.empty())
    {
      int node = heap.top().first;
      int d = heap.top().second;
      heap.pop();
      if (!visited[node])
      {
        visited[node] = true;
        res += d;

        for (int i = 0; i < adj[node].size(); i++)
        {
          int neigh = adj[node][i].first;
          int w = adj[node][i].second;
          if (!visited[neigh])
          {
            heap.push({neigh, w});
          }
        }
      }
    }
    return res;
  }
};