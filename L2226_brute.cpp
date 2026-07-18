#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int countCandies(vector<int> &candies, int val)
  {
    int res = 0;
    for (int i = 0; i < candies.size(); i++)
    {
      if (candies[i] == val)
      {
        res++;
      }
    }
    return res;
  }

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
      vector<int> c = candies;
      long long count = countCandies(c, mid);

      if (count < k)
      {
        while (true)
        {

          int currSize = c.size();

          // check it..

          // divide it...
          for (int i = 0; i < currSize; i++)
          {
            if (c[i] > mid)
            {
              // we can divide it into piles..
              c[i] = c[i] - mid;
              c.push_back(mid);
            }
          }

          int newSize = c.size();
          // cout << newSize << " , "<< currSize <<endl;
          if (currSize == newSize)
          {
            break;
          }
        }

        // now count again in c...
        int newCount = countCandies(c, mid);
        if (newCount < k)
        {
          high = mid - 1;
        }
        else
        {
          low = mid + 1;
          res = max(res, mid);
        }
      }
      else
      {
        res = max(res, mid);
        low = mid + 1;
      }
    }

    return res;
  }
};