#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<bool>> visited; // to get whether it could be a bool or not...
  vector<int> findNewLand(vector<vector<char>> &grid)
  {
    int row = -1;
    int col = -1;
    vector<int> res(2);
    res[0] = -1;
    res[1] = -1;

    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[0].size(); j++)
      {
        if (visited[i][j] == false && grid[i][j] == '1')
        {
          res[0] = i;
          res[1] = j;
        }
      }
    }
    return res;
  }

  void helperFind(vector<vector<char>> &grid, int x, int y)
  {
    int leftMax = 0;
    int rightMax = grid[0].size() - 1;
    int upMax = 0;
    int bottomMax = grid.size() - 1;

    if (x >= upMax && x <= bottomMax && y >= leftMax && y <= rightMax)
    {
      if (grid[x][y] == '1' && !visited[x][y])
      {
        visited[x][y] = true;
        helperFind(grid, x + 1, y);
        helperFind(grid, x - 1, y);
        helperFind(grid, x, y + 1);
        helperFind(grid, x, y - 1);
      }
      return;
    }
    else
    {
      return;
    }
  }

  bool allVisited(vector<vector<char>> &grid)
  {
    for (int i = 0; i < visited.size(); i++)
    {
      for (int j = 0; j < visited[0].size(); j++)
      {
        if (visited[i][j] == false && grid[i][j] == '1')
        {
          return false;
        }
      }
    }
    return true;
  }

  int numIslands(vector<vector<char>> &grid)
  {
    int numOfIslands = 0;

    visited.assign(grid.size(), vector<bool>(grid[0].size(), 0));

    // while (!allVisited(grid))
    // {
    //   vector<int> landCor = findNewLand(grid);
    //   int row = landCor[0];
    //   int col = landCor[1];
    //   if (row != -1 && col != -1)
    //   {
    //     numOfIslands++;
    //     // do recursion to check for left , right, bottom , and up..
    //     helperFind(grid, row, col);
    //     vector<int> landCor2 = findNewLand(grid);
    //     row = landCor2[0];
    //     col = landCor2[1];
    //   }
    // }

    for(int i =0;i<grid.size();i++)
    {
      for(int j =0;j<grid[0].size();j++)
      {
        if(grid[i][j] == '1')
        {
          numOfIslands++;
          helperFind(grid,i,j);
        }
      }
    }
    return numOfIslands;
  }
};