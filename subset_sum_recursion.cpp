#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void helperFunc(vector<int> &arr, int currSum, int sum, int idx, bool &res)
  {

    if (currSum == sum)
    {
      res = true;
      return;
    }

    if (currSum > sum)
    {
      return;
    }

    if (idx == arr.size())
    {
      return;
    }
    else
    {
      // if not , include that number, and then see possibilities...
      helperFunc(arr, currSum + arr[idx], sum, idx + 1, res);
      // now see without taking that number , all the possibilities...
      helperFunc(arr, currSum, sum, idx + 1, res);
      return;
    }
  }

  bool isSubsetSum(vector<int> &arr, int sum)
  {
    // code here
    // just do it by recursion and backtracking...
    bool res = false;
    helperFunc(arr, 0, sum, 0, res);
    return res;
  }
};