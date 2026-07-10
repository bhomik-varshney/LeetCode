#include <iostream>
#include <queue>
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
  vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
  {
    // Code here

    // make adj list
    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < edges.size(); i++)
    {
      int u = edges[i][0];
      int v = edges[i][1];
      int w = edges[i][2];
      pair<int, int> p1 = {v, w};
      pair<int, int> p2 = {u, w};
      adj[u].push_back(p1);
      adj[v].push_back(p2);
    }
    vector<int> dis(V, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> heap; // {node, distance}
    pair<int, int> p = {src, 0};
    heap.push(p);

    while (!heap.empty())
    {
      int node = heap.top().first;
      int d = heap.top().second;
      heap.pop();

      // now see if the currentValue of dis is less than d, then ignore it, it was a previous relaxed one..
      if (dis[node] > d)
      {
        dis[node] = d;

        // now relax the neighbours...
        for (int i = 0; i < adj[node].size(); i++)
        {
          int neighbour = adj[node][i].first;
          int weight = adj[node][i].second;

          if (dis[node] + weight < dis[neighbour])
          {
            pair<int, int> p3 = {neighbour, dis[node] + weight};
            heap.push(p3);
          }
        }
      }
    }

    return dis;
  }
};