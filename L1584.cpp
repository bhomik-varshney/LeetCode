#include <iostream>
#include <vector>
using namespace std;

struct cmp
{
  bool operator()(pair<int, int> &a, pair<int, int> &b)
  {
    if (a.first > b.first)
    {
      return true; // min heap
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
  int minCostConnectPoints(vector<vector<int>> &points)
  {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> heap; // it will store as :- {distance,index}

    // we have to make an MST...
    vector<bool> visited(points.size(), false);

    int totalCost = 0;
    heap.push({0, 0});
    while (!heap.empty())
    {
      int dis = heap.top().first;
      int idx = heap.top().second;
      heap.pop();
      int x1 = points[idx][0];
      int y1 = points[idx][1];
      if (visited[idx])
      {
        continue;
      }
      else
      {
        // now add the distance to the totalCost..
        visited[idx] = true;
        totalCost += dis;
        // now add the distance of its neighbours..
        for (int i = 0; i < points.size(); i++)
        {
          if (!visited[i])
          {
            int x2 = points[i][0];
            int y2 = points[i][1];

            // see distance and add into the heap..
            int d = abs(x2 - x1) + abs(y2 - y1);
            heap.push({d, i});
          }
        }
      }
    }

    return totalCost;
  }
};