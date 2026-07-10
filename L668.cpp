#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  bool exist(int m, int n, int val)
  {
    int maxRow = m - 1;
    int maxCol = n - 1;

    int row = maxRow;
    int col = 0;

    bool res = false;

    while (row >= 0 && col <= maxCol)
    {
      if (((row + 1) * (col + 1)) < val)
      {
        // delete the particular column...
        col++;
      }
      else if (((row + 1) * (col + 1)) > val)
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

  int numBefore(int m, int n, int val)
  {
    int row = 0;
    int col = n - 1;

    int maxRow = m - 1;
    int maxCol = n - 1;

    int res = 0;

    while (row <= maxRow && col >= 0)
    {
      if (((row + 1) * (col + 1)) <= val)
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

  int findKthNumber(int m, int n, int k)
  {
    int size = m;
    int low = 1;
    int high = m * n;
    int res = -1;

    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (numBefore(m, n, mid) >= k)
      {
        if (exist(m, n, mid))
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
  Solution s1;
  cout << s1.findKthNumber(9895, 28405, 100787757);
}