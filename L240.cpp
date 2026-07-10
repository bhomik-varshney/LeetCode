#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int row = matrix.size() - 1;
    int col = 0;

    int maxRow = matrix.size() - 1;
    int maxCol = matrix[0].size() - 1;

    while (row >= 0 && col <= maxCol)
    {
      if (matrix[row][col] == target)
      {
        return true;
        break;
      }
      else if (matrix[row][col] > target)
      {
        // eliminate the particular row...
        row--;
      }
      else
      {
        // eliminate the particular column...
        col++;
      }
    }

    return false;
  }
};

int main()
{
  Solution s1;
  vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
  cout << s1.searchMatrix(matrix, 3);
}
