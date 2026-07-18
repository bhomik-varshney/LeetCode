#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int findMax(vector<int> &candies)
  {
    // find the value of maximum in candies...
    int maximum = INT_MIN;
    for (int i = 0; i < candies.size(); i++)
    {
      if (candies[i] > maximum)
      {
        maximum = candies[i];
      }
    }
    return maximum;
  }

  int maximumCandies(vector<int> &candies, long long k)
  {
    int res = 0;
    // brute force is to use binary search in it...
    int low = 1;
    int high = findMax(candies);

    while (low <= high)
    {
      int mid = low + ((high - low) / 2);

      // find if we could find the possible solution for mid value or not...
      long long count = 0;
      for (int i = 0; i < candies.size(); i++)
      {
        count += candies[i] / mid;
      }

      if (count < k)
      {
        high = mid - 1;
      }
      else
      {
        // this could be the answer, but we are seeing the better one...
        res = max(res, mid);
        low = mid + 1;
      }
    }

    return res;
  }
};