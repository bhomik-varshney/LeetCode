#include <iostream>
#include <vector>
using namespace std;

// array of int no of subarrays that have a cost <= k
//  cost = (max-min)* length of the subarray
//  length = 10^5
//  k = 10^15
//  elements of array = 10^9
//  cost = 10^15

class Solution
{
public:
  void minMax(vector<int> arr, int low, int high, int &min, int &max)
  {
    int minIndex = -1;
    int minValue = INT_MAX;
    int maxIndex = -1;
    int maxValue = INT_MIN;
    for (int i = low; i <= high; i++)
    {
      if (minValue > arr[i])
      {
        minIndex = i;
        minValue = arr[i];
      }
      if (maxValue < arr[i])
      {
        maxIndex = i;
        maxValue = arr[i];
      }
    }
    max = maxValue;
    min = minValue;
  }
  int noOfSubarrays(vector<int> arr, int cost)
  {
    int low = 0;
    int high = 0;
    int max = arr[0];
    int min = arr[0];
    int res = 0;
    while (low <= high && high < arr.size()) // O(n)
    {
      minMax(arr, low, high, min, max); // O(n)
      // cout << min << " , " << max << endl;
      int currentCost = (max - min) * (high - low + 1); // O(1)

      if (currentCost <= cost) // O(1)
      {
        res += (high - low + 1);
        high++;
      }
      else // O(1)
      {
        low++;
      }
    }

    return res;
  }

  // total time complexity = O(n^2), total space complexity = O(1), no extra space used
};

int main()
{
  vector<int> v = {4, 1, 3, 2, 5};
  int cost = 6;
  Solution s1;
  cout << s1.noOfSubarrays(v, cost);
}