#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    vector<int> res;
    int i = 0;
    int j = 0;
    while (i < m && j < n)
    {
      int x = nums1[i];
      int y = nums2[j];
      if (x < y)
      {
        res.push_back(x);
        i++;
      }
      else
      {
        res.push_back(y);
        j++;
      }
    }

    while (i < m)
    {
      res.push_back(nums1[i]);
      i++;
    }
    while (j < n)
    {
      res.push_back(nums2[j]);
      j++;
    }

    nums1 = res;
    return;
  }
};