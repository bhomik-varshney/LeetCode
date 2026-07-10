#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int helperFunc(vector<int> &arr, int sumReq, int currIndex)
  {
    if (currIndex == arr.size())
    {
      // then check the sumReq...
      if (sumReq == 0)
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }

    int val = arr[currIndex];

    // first add this to target...
    int a1 = helperFunc(arr, sumReq - val, currIndex + 1);
    // second, remove from the target...
    int a2 = helperFunc(arr, sumReq + val, currIndex + 1);

    return a1 + a2;
  }

  int totalWays(vector<int> &arr, int target)
  {
    //  code here
    // we can either add this to our target or decrease it to our target...
    // if we add it, target decreases, and if we subtract it, the target increases..
    return helperFunc(arr, target, 0);
  }
};