#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int func(vector<int> &arr, int n)
  {
    if (n == 1)
    {
      return arr[0];
    }
    int maxi = func(arr, n - 1);
    return max(maxi, arr[n - 1]);
  }
};

int main()
{
  vector<int> arr = {-3, -10, -34, -10, -34, -20};
  Solution s1;
  cout << s1.func(arr, arr.size());
}