#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  long long countTriplets(int n, long long target, long long arr[])
  {
    sort(arr, arr + n);
    long long count = 0;
    // Your code goes here
    for (int k = 0; k < n - 2; k++)
    {
      int i = k + 1;
      int j = n - 1;
      long long newTarget = target - arr[k];
      while (i < j)
      {
        long long sum = arr[i] + arr[j];
        if (sum < newTarget)
        {
          count += j - i;
          i++;
        }
        else if (sum > newTarget)
        {
          j--;
        }
        else
        {
          j--;
        }
      }
    }

    return count;
  }
};

int main()
{
  Solution s1;
  long long arr[] = {-2, 0, 1, 3};
  long long result = s1.countTriplets(4, 2, arr);
  cout << result;
}