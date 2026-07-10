#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void BFS(vector<vector<int>> &grid, queue<pair<int, int>> &q, int &minutes)
  {
    int leftMax = 0;
    int rightMax = grid[0].size() - 1;
    int upMax = 0;
    int bottomMax = grid.size() - 1;

    while (!q.empty())
    {
      int size = q.size();
      bool alreadyIncreased = false;
      // nearby all fresh (or 1) oranges must be 2...

      while (size != 0)
      {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // check the left
        if (col - 1 >= leftMax)
        {
          if (grid[row][col - 1] == 1)
          {
            grid[row][col - 1] = 2;
            pair<int, int> p = {row, col - 1};
            q.push(p);
            if (!alreadyIncreased)
            {
              minutes++;
              alreadyIncreased = true;
            }
          }
        }
        // check the right
        if (col + 1 <= rightMax)
        {
          if (grid[row][col + 1] == 1)
          {
            grid[row][col + 1] = 2;
            pair<int, int> p = {row, col + 1};
            q.push(p);
            if (!alreadyIncreased)
            {
              minutes++;
              alreadyIncreased = true;
            }
          }
        }
        // check the up
        if (row - 1 >= upMax)
        {
          if (grid[row - 1][col] == 1)
          {
            grid[row - 1][col] = 2;
            pair<int, int> p = {row - 1, col};
            q.push(p);
            if (!alreadyIncreased)
            {
              minutes++;
              alreadyIncreased = true;
            }
          }
        }
        // check the bottom
        if (row + 1 <= bottomMax)
        {
          if (grid[row + 1][col] == 1)
          {
            grid[row + 1][col] = 2;
            pair<int, int> p = {row + 1, col};
            q.push(p);
            if (!alreadyIncreased)
            {
              minutes++;
              alreadyIncreased = true;
            }
          }
        }
        size--;
      }
    }

    return;
  }

  bool calcFresh(vector<vector<int>> &grid)
  {
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[0].size(); j++)
      {
        if (grid[i][j] == 1)
        {
          return true;
        }
      }
    }
    return false;
  }

  int orangesRotting(vector<vector<int>> &grid)
  {
    // push into the queue, the rotten oranges...
    queue<pair<int, int>> q;
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[0].size(); j++)
      {
        if (grid[i][j] == 2)
        {
          pair<int, int> p = {i, j};
          q.push(p);
        }
      }
    }

    int minutes = 0;
    BFS(grid, q, minutes);

    if (calcFresh(grid))
    {
      return -1;
    }
    else
    {
      return minutes;
    }
  }
};