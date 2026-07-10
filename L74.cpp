#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int low = 0;
    int high = matrix.size() - 1;
    int col = matrix[0].size();
    bool res = false;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (target >= matrix[mid][0] && target <= matrix[mid][col - 1])
      {
        // search the target element in that using binary searcg...
        int low2 = 0;
        int high2 = col - 1;
        while (low2 <= high2)
        {
          int mid2 = (low2 + high2) / 2;
          if (matrix[mid][mid2] == target)
          {
            return true;
          }
          else if (matrix[mid][mid2] < target)
          {
            low2 = mid2 + 1;
          }
          else
          {
            high2 = mid2 - 1;
          }
        }
        return false;
      }
      else if (target < matrix[mid][0] && target < matrix[mid][col - 1])
      {
        // then we have to decrease the value of high...
        high = mid - 1;
      }
      else if (target > matrix[mid][0] && target > matrix[mid][col - 1])
      {
        // change the low value...
        low = mid + 1;
      }
    }

    return false;
  }
};

int main()
{
  vector<vector<int>> v1 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {20, 30, 34, 60}};
  Solution s1;
  cout << s1.searchMatrix(v1, 3);
}