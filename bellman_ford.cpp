#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
  {
    // Code here
    vector<int> dis(V, 100000000);
    dis[src] = 0;
    for (int itr = 0; itr < V - 1; itr++)
    {
      // now relax every edge...
      for (int i = 0; i < edges.size(); i++)
      {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if (dis[u] != 100000000)
        {
          // now relax it...
          if (dis[v] > dis[u] + w)
          {
            dis[v] = dis[u] + w;
          }
        }
      }
    }

    // to check negative cycle...
    for (int i = 0; i < edges.size(); i++)
    {
      int u = edges[i][0];
      int v = edges[i][1];
      int w = edges[i][2];

      if (dis[u] != 100000000)
      {
        // now relax it...
        if (dis[v] > dis[u] + w)
        {
          // means there is a relaxation, return -1;
          vector<int> res(1, -1);
          return res;
        }
      }
    }
    return dis;
  }
};