#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  bool validMove(int x, int y)
  {
    int leftMax = 0;
    int rightMax = 7;
    int upMax = 0;
    int downMax = 7;

    if (x >= upMax && x <= downMax && y >= leftMax && y <= rightMax)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool checkReach(vector<int> start, vector<int> &target, vector<vector<bool>> &visited, int moves)
  {
    // make it visited..
    visited[start[0]][start[1]] = true;
    if (start[0] == target[0] && start[1] == target[1] && moves % 2 == 0)
    {
      return true;
    }

    // now check if we can reach by moving up, left, right and down..

    vector<int> x = {2, 2, -2, -2, -1, 1, -1, 1};
    vector<int> y = {1, -1, 1, -1, 2, 2, -2, -2};
    for (int i = 0; i < 8; i++)
    {
      int newX = start[0] + x[i];
      int newY = start[1] + y[i];
      if (validMove(newX, newY) && !visited[newX][newY])
      {
        vector<int> corr;
        corr.push_back(newX);
        corr.push_back(newY);
        bool res = checkReach(corr, target, visited, moves + 1);
        if (res)
        {
          return true;
        }
      }
    }

    return false;
  }

  bool canReach(vector<int> &start, vector<int> &target)
  {
    // board size is 8x8...
    vector<vector<bool>> visited(8, vector<bool>(8, false));
    return checkReach(start, target, visited, 0);
  }
};