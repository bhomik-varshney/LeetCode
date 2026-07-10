#include <iostream>
#include <vector>
using namespace std;

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

  bool isReachable(vector<vector<int>> &grid, int money, int currX, int currY, int desX, int desY, vector<vector<bool>> &visited)
  {
    vector<int> x = {-1, 1, 0, 0};
    vector<int> y = {0, 0, -1, 1};

    if (money >= grid[currX][currY])
    {
      visited[currX][currY] = true;
      if (currX == desX && currY == desY)
      {
        return true;
      }
      else
      {
        // means it can reach the curr location but right now not at destination, so just check its all 4 directions
        for (int i = 0; i < 4; i++)
        {
          int newX = currX + x[i];
          int newY = currY + y[i];
          if (isValid(grid, newX, newY) && !visited[newX][newY])
          {
            bool localRes = isReachable(grid, money, newX, newY, desX, desY, visited);
            if (localRes)
            {
              return true;
            }
          }
        }
        return false;
      }
    }
    else
    {
      return false;
    }
  }

  int swimInWater(vector<vector<int>> &grid)
  {
    int low = 0;
    int high = maxGrid(grid);
    int size = grid.size();
    int res = high;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      vector<vector<bool>> visited(size, vector<bool>(size, false));
      if (isReachable(grid, mid, 0, 0, size - 1, size - 1, visited))
      {
        // put the high to be mid-1...
        res = mid;
        high = mid - 1;
      }
      else
      {
        // put the low to be mid+1
        low = mid + 1;
      }
    }
    return res;
  }
};