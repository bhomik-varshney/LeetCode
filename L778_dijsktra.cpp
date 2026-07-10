#include <iostream>
#include <vector>
using namespace std;

struct cmp
{
  bool operator()(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)
  {
    if (a.first > b.first)
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
  int maxGrid(vector<vector<int>> &grid)
  {
    int res = INT_MIN;
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid.size(); j++)
      {
        if (grid[i][j] > res)
        {
          res = grid[i][j];
        }
      }
    }
    return res;
  }

  bool isValid(vector<vector<int>> &grid, int x, int y)
  {
    int upMax = 0;
    int downMax = grid.size() - 1;
    int leftMax = 0;
    int rightMax = downMax;

    if (x >= upMax && x <= downMax && y >= leftMax && y <= rightMax)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  int swimInWater(vector<vector<int>> &grid)
  {
    // using dijsktra's algorithm
    int size = grid.size();
    vector<vector<int>> res(size, vector<int>(size, maxGrid(grid)));
    vector<int> x = {-1, 1, 0, 0};
    vector<int> y = {0, 0, -1, 1};

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> heap;
    pair<int, int> p1 = {0, 0};
    pair<int, pair<int, int>> p2 = {grid[0][0], p1};
    heap.push(p2);
    while (!heap.empty())
    {
      int money = heap.top().first;
      int currX = heap.top().second.first;
      int currY = heap.top().second.second;
      heap.pop();
      if (money < res[currX][currY])
      {
        res[currX][currY] = money;

        // check immediate neighbours...
        for (int i = 0; i < 4; i++)
        {
          int neighX = currX + x[i];
          int neighY = currY + y[i];

          if (isValid(grid, neighX, neighY))
          {
            int moneyReq = grid[neighX][neighY];
            if (moneyReq >= money)
            {
              pair<int, int> p3 = {neighX, neighY};
              pair<int, pair<int, int>> p4 = {moneyReq, p3};
              heap.push(p4);
            }
            else
            {
              // moneyReq < money
              pair<int, int> p3 = {neighX, neighY};
              pair<int, pair<int, int>> p4 = {money, p3};
              heap.push(p4);
            }
          }
        }
      }
    }

    return res[size - 1][size - 1];
  }
};