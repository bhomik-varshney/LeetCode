#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int findMax(vector<int> &stalls)
  {
    int idx = -1;
    int maxVal = INT_MIN;

    for (int i = 0; i < stalls.size(); i++)
    {
      if (stalls[i] > maxVal)
      {
        idx = i;
        maxVal = stalls[i];
      }
    }
    return maxVal;
  }

  bool check(vector<int> &stalls, int k, int val)
  {
    int cows = 1;
    int prevPos = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
      int dis = abs(stalls[i] - prevPos);
      if (dis >= val)
      {
        cows++;
        prevPos = stalls[i];
      }
    }

    if (cows >= k)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  int aggressiveCows(vector<int> &stalls, int k)
  {
    sort(stalls.begin(), stalls.end());
    int low = 1;
    int high = findMax(stalls);

    int res = 1;

    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (check(stalls, k, mid))
      {
        if (res < mid)
        {
          res = mid;
        }
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }

    return res;
  }
};

int main()
{
  Solution s1;
  vector<int> stalls = {1, 2, 4, 8, 9};
  cout << s1.aggressiveCows(stalls, 5) << endl;
}