#include <iostream>
using namespace std;

// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
// Return the index of the peak element.
// Your task is to solve it in O(log(n)) time complexity.
// Example 1:
// Input: arr = [0,1,0]
// Output: 1

class Solution
{
public:
  int peakIndexInMountainArray(vector<int> &arr)
  {
    int res = INT_MIN;
    int idx = -1;
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (mid != 0 && mid != arr.size() - 1)
      {
        if (arr[mid - 1] < arr[mid] && arr[mid + 1] < arr[mid])
        {
          // then we have to peak value....
          idx = mid;
          res = arr[mid];
          break;
        }
        else if (arr[mid - 1] < arr[mid] && arr[mid + 1] > arr[mid])
        {
          low = mid + 1;
        }
        else
        {
          high = mid - 1;
        }
      }
    }

    return idx;
  }
};