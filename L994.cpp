#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int calcFresh(vector<vector<int>> &grid)
  {
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[0].size(); j++)
      {
        if (grid[i][j] == 1)
        {
          count++;
        }
      }
    }
    return count;
  }

  void BFS(vector<vector<int>> &grid, int row, int col, int &newNumOfFresh, int val)
  {
    // check that
    int upMax = 0;
    int leftMax = 0;
    int rightMax = grid[0].size() - 1;
    int bottomMax = grid.size() - 1;
    if (row - 1 >= upMax)
    {
      if (grid[row - 1][col] == 1)
      {
        newNumOfFresh--;
        grid[row - 1][col] = val;
      }
    }

    if (row + 1 <= bottomMax)
    {
      if (grid[row + 1][col] == 1)
      {
        newNumOfFresh--;
        grid[row + 1][col] = val;
      }
    }
    if (col + 1 <= rightMax)
    {
      if (grid[row][col + 1] == 1)
      {
        newNumOfFresh--;
        grid[row][col + 1] = val;
      }
    }
    if (col - 1 >= leftMax)
    {
      if (grid[row][col - 1] == 1)
      {
        newNumOfFresh--;
        grid[row][col - 1] = val;
      }
    }
    return;
  }

  int orangesRotting(vector<vector<int>> &grid)
  {
    int numOfFresh = calcFresh(grid); // O(mn)
    int minutes = 0;
    int rottenOnes = 2;
    int newNumOfFresh = numOfFresh;
    if (numOfFresh != 0)
    {
      // search for every rotten orange and make the affected ones to be 3.. after the minute ends..
      for (int i = 0; i < grid.size(); i++) // O(m)
      {
        for (int j = 0; j < grid[0].size(); j++) // O(n)
        {
          if (grid[i][j] == rottenOnes)
          {
            BFS(grid, i, j, newNumOfFresh, rottenOnes + 1); // O(1)
          }
        }
      }

      rottenOnes++;
      while (numOfFresh != newNumOfFresh) // O(minutes)
      {
        int temp = newNumOfFresh;
        for (int i = 0; i < grid.size(); i++) // O(m)
        {
          for (int j = 0; j < grid[0].size(); j++) // O(n)
          {
            if (grid[i][j] == rottenOnes)
            {
              BFS(grid, i, j, newNumOfFresh, rottenOnes + 1); // O(1)
            }
          }
        }

        numOfFresh = temp;
        rottenOnes++;
        minutes++;
      }

      if (newNumOfFresh == numOfFresh && newNumOfFresh == 0)
      {
        return minutes;
      }
      else
      {
        return -1;
      }
    }
    else
    {
      return 0;
    }
  }
};

// total time complexity is O(mno), where o is the number of iterations till prevFresh = currentFresh
// worst case would be O((mn)^2)