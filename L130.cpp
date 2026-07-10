#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void DFS(vector<vector<char>> &board, int row, int col, vector<vector<bool>> &visited)
  {
    visited[row][col] = true;
    // now all the connecting O to it must also be visited...
    int leftMax = 0;
    int rightMax = board[0].size() - 1;
    int upMax = 0;
    int downMax = board.size() - 1;

    if (row - 1 >= upMax && row - 1 <= downMax && board[row - 1][col] == 'O' && !visited[row - 1][col])
    {
      DFS(board, row - 1, col, visited);
    }
    if (row + 1 >= upMax && row + 1 <= downMax && board[row + 1][col] == 'O' && !visited[row + 1][col])
    {
      DFS(board, row + 1, col, visited);
    }
    if (col - 1 >= leftMax && col - 1 <= rightMax && board[row][col - 1] == 'O' && !visited[row][col - 1])
    {
      DFS(board, row, col - 1, visited);
    }
    if (col + 1 >= leftMax && col + 1 <= rightMax && board[row][col + 1] == 'O' && !visited[row][col + 1])
    {
      DFS(board, row, col + 1, visited);
    }
    return;
  }

  void solve(vector<vector<char>> &board)
  {
    int row = 0;
    int col = 0;
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    while (col != board[0].size())
    {
      // find the O on the edges...
      if (board[row][col] == 'O' && !visited[row][col])
      {
        DFS(board, row, col, visited);
      }
      col++;
    }
    col--;
    while (row != board.size())
    {
      if (board[row][col] == 'O' && !visited[row][col])
      {
        DFS(board, row, col, visited);
      }
      row++;
    }
    row--;

    while (col != -1)
    {
      if (board[row][col] == 'O' && !visited[row][col])
      {
        DFS(board, row, col, visited);
      }
      col--;
    }
    col++;

    while (row != -1)
    {
      if (board[row][col] == 'O' && !visited[row][col])
      {
        DFS(board, row, col, visited);
      }
      row--;
    }

    // now the one who are O and not visited. make them to X
    for (int i = 0; i < board.size(); i++)
    {
      for (int j = 0; j < board[0].size(); j++)
      {
        if (board[i][j] == 'O' && !visited[i][j])
        {
          board[i][j] = 'X';
        }
      }
    }
    return;
  }
};


// Note:- to make the space complexity to be O(1), simply instead of visited, make the edge O and connect to that edge O to be #, and at last, convert # to O and O to X