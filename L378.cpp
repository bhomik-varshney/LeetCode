#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  bool exist(vector<vector<int>> matrix, int val)
  {
    int maxRow = matrix.size() - 1;
    int maxCol = matrix[0].size() - 1;

    int row = maxRow;
    int col = 0;

    bool res = false;

    while (row >= 0 && col <= maxCol)
    {
      if (matrix[row][col] < val)
      {
        // delete the particular column...
        col++;
      }
      else if (matrix[row][col] > val)
      {
        // delete the particular row...
        row--;
      }
      else
      {
        return true;
      }
    }

    return false;
  }

  int numBefore(vector<vector<int>> matrix, int val)
  {
    int row = 0;
    int col = matrix[0].size() - 1;

    int maxRow = matrix.size() - 1;
    int maxCol = matrix[0].size() - 1;

    int res = 0;

    while (row <= matrix.size() - 1 && col >= 0)
    {
      if (matrix[row][col] <= val)
      {
        // then that whole row elements will be smaller than that...
        res += col + 1;
        row++;
      }
      else
      {
        // decrease the column value...
        col--;
      }
    }
    return res;
  }

  int kthSmallest(vector<vector<int>> &matrix, int k)
  {

    int size = matrix.size();
    int low = matrix[0][0];
    int high = matrix[size - 1][size - 1];
    int res = -1;

    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (numBefore(matrix, mid) >= k)
      {
        if (exist(matrix, mid))
        {
          res = mid;
        }
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }

    return res;
  }
};

int main()
{
  vector<vector<int>> matrix = {{1, 2}, {1, 3}};
  Solution s1;
  cout << s1.kthSmallest(matrix, 1);
}