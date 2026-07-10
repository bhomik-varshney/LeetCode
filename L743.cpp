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
  int networkDelayTime(vector<vector<int>> &times, int n, int k)
  {
    vector<vector<pair<int, int>>> adj(n + 1); // 0 will always be empty.. so it would be 1 to n
    for (int i = 0; i < times.size(); i++)
    {
      int src = times[i][0];
      int des = times[i][1];
      int t = times[i][2];
      pair<int, int> p1 = {des, t};

      adj[src].push_back(p1);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> heap;
    vector<int> dis(n + 1, INT_MAX);
    pair<int, int> p = {k, 0};
    heap.push(p);
    while (!heap.empty())
    {
      int node = heap.top().first;
      int d = heap.top().second;
      heap.pop();
      if (dis[node] > d)
      {
        dis[node] = d;
        // now relax the neighbours...
        for (int i = 0; i < adj[node].size(); i++)
        {
          int neighbour = adj[node][i].first;
          int w = adj[node][i].second;

          if (dis[node] + w < dis[neighbour])
          {
            pair<int, int> p1 = {neighbour, dis[node] + w};
            heap.push(p1);
          }
        }
      }
    }

    // now we have complete distance vector. find the maximum one from the dis ignoring INT_MAX...
    int res = INT_MIN;
    for (int i = 1; i < dis.size(); i++)
    {
      if (dis[i] == INT_MAX)
      {
        return -1;
      }
      else
      {
        if (dis[i] > res)
        {
          res = dis[i];
        }
      }
    }
    return res;
  }
};