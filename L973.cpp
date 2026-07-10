#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

struct cmp
{
  bool operator()(pair<vector<int>, double> &a, pair<vector<int>, double> &b)
  {
    // we have to make max heap...
    if (a.second > b.second)
    {
      return false;
    }
    else
    {
      return true;
    }
  }
};

class Solution
{
public:
  double Dist(int x1, int y1, int x2, int y2)
  {
    double x = (x1 - x2);
    x = pow(x, 2);
    double y = (y1 - y2);
    y = pow(y, 2);
    double res = sqrt(x + y);
    return res;
  }
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
  {
    vector<vector<int>> res;
    // we have to find the k min values having distance to be minimum from the origin..
    // desired approach is using heap...
    map<pair<vector<int>, double>, int> map;
    // stores as:- [x,y],dist -> occurence
    for (int i = 0; i < points.size(); i++)
    {
      int x = points[i][0];
      int y = points[i][1];
      vector<int> corr = {x, y};
      pair<vector<int>, double> p = {corr, Dist(x, y, 0, 0)};
      map[p]++;
    }

    // now use the max heap to find the minimum points...
    priority_queue<pair<vector<int>, double>, vector<pair<vector<int>, double>>, cmp> heap;

    for (auto i : map)
    {
      vector<int> corr = i.first.first;
      pair<vector<int>, double> p = {corr, i.first.second};
      if (heap.size() < k && i.second <= k)
      {
        for (int j = 0; j < i.second; j++)
        {
          heap.push(p);
        }
        i.second = 0;
      }
      else if (heap.size() < k && i.second > k)
      {
        i.second = i.second - k;
        for (int j = 0; j < k; j++)
        {
          heap.push(p);
        }
      }
      else
      {
        while (i.second > 0 && heap.top().second > i.first.second)
        {
          heap.pop();
          heap.push(p);
          i.second--;
        }
      }
    }

    while (!heap.empty())
    {
      res.push_back(heap.top().first);
      heap.pop();
    }

    return res;
  }
};

int main()
{
  vector<vector<int>> points = {{2, 2}, {2, 2}, {3, 3}, {2, -2}, {1, 1}};
  int k = 4;
  Solution s1;
  vector<vector<int>> res;
  res = s1.kClosest(points, k);
  for (int i = 0; i < res.size(); i++)
  {
    cout << "[ " << res[i][0] << " , " << res[i][1] << " ]" << endl;
  }
}