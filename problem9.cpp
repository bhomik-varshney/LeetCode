#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int maxSubarraySum(vector<int> &arr, int k)
  {
    // code here
    if (arr.size() != 0)
    {
      int low = 0;
      int high = k - 1;
      int result = 0;
      int sum = 0;
      while (high <= arr.size() - 1)
      {

        if (low == 0)
        {
          for (int i = 0; i <= high; i++)
          {
            sum += arr[i];
          }
        }
        else
        {

          sum -= arr[low - 1];
          sum += arr[high];
        }
        if (sum > result)
        {
          result = sum;
        }

        low++;
        high++;
      }
      return result;
    }
    else
    {
      return 0;
    }
  }
};

int main()
{
  vector<int> v = {1, 4, 2, 10, 23, 3, 1, 0, 20};
  Solution s1;
  int result = s1.maxSubarraySum(v, 4);
  cout << result;
}