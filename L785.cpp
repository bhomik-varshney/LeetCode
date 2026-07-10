#include <iostream>
#include <queue>
using namespace std;

class Solution
{
public:
  bool isBipartite(vector<vector<int>> &graph)
  {
    int V = graph.size();
    vector<int> color(V, 0);
    vector<bool> visited(V, false);
    // -1 red , 0 -> no color , 1 -> blue
    queue<int> q;

    for (int i = 0; i < V; i++)
    {
      if (!visited[i])
      {
        q.push(i);
        visited[i] = true;
        color[i] = -1;
        while (!q.empty())
        {
          int node = q.front();
          q.pop();
          for (int i = 0; i < graph[node].size(); i++)
          {

            int neighbour = graph[node][i];
            int neighbourColor = color[neighbour];
            int parentColor = color[node];
            if (visited[neighbour])
            {
              if (parentColor == neighbourColor)
              {
                return false;
              }
            }
            else
            {
              if (parentColor == 1)
              {
                color[neighbour] = -1;
              }
              if (parentColor == -1)
              {
                color[neighbour] = 1;
              }
              q.push(neighbour);
              visited[neighbour] = true;
            }
          }
        }
      }
    }
    return true;
  }
};