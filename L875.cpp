#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int maxVal(vector<int> &piles)
  {
    int idx = -1;
    int val = INT_MIN;

    for (int i = 0; i < piles.size(); i++)
    {
      if (piles[i] > val)
      {
        val = piles[i];
        idx = i;
      }
    }
    return val;
  }

  bool canEat(vector<int> &piles, int h, int k)
  {
    int hours = 0;

    for (int i = 0; i < piles.size(); i++)
    {
      hours += (piles[i] + k - 1) / k;
    }
    if (hours <= h)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  int minEatingSpeed(vector<int> &piles, int h)
  {
    int res = maxVal(piles);
    int low = 1;
    int high = res;

    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (canEat(piles, h, mid))
      {
        if (res > mid)
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

  vector<int> piles = {3, 6, 7, 11};
  Solution s1;
  cout << s1.minEatingSpeed(piles, 8);
}