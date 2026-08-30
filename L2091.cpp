#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution
{
public:
  int minimumDeletions(vector<int> &nums)
  {

    if (nums.size() == 1)
    {
      return 1;
    }
    // find minimum and maximum, with their index values...
    int maxVal = INT_MIN;
    int maxIdx = -1;
    int minVal = INT_MAX;
    int minIdx = -1;

    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] > maxVal)
      {
        maxVal = nums[i];
        maxIdx = i;
      }

      if (nums[i] < minVal)
      {
        minVal = nums[i];
        minIdx = i;
      }
    }
    int res1 = 0;
    int res2 = INT_MAX;

    vector<pair<int, int>> Intervals;

    Intervals.push_back({0, maxIdx});
    Intervals.push_back({maxIdx, nums.size() - 1});

    Intervals.push_back({0, minIdx});
    Intervals.push_back({minIdx, nums.size() - 1});

    // now go for checking...
    for (int i = 0; i < Intervals.size(); i++)
    {
      int first = Intervals[i].first;
      int sec = Intervals[i].second;

      if (minIdx >= first && minIdx <= sec && maxIdx >= first && maxIdx <= sec)
      {
        // possible answer...
        res2 = min(res2, sec - first + 1);
      }
      else
      {
        // they both are not in this range....
        res1 += sec - first + 1;
      }
    }

    return min(res1, res2);
  }
};