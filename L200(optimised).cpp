#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:

  void helperFind(vector<vector<char>> &grid, int x, int y)
  {
    int leftMax = 0;
    int rightMax = grid[0].size() - 1;
    int upMax = 0;
    int bottomMax = grid.size() - 1;

    if (x >= upMax && x <= bottomMax && y >= leftMax && y <= rightMax)
    {
      if (grid[x][y] == '1')
      {
        grid[x][y] = '2';
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

  int numIslands(vector<vector<char>> &grid)
  {
    int numOfIslands = 0;

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