#include <iostream>
#include <vector>
using namespace std;

// we can simply do it in O(nlogn) or O(n^2), but lets see how can we do it in O(n)...

class Solution
{
public:
  vector<int> sortedSquares(vector<int> &nums)
  {
    int index = nums.size() - 1;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] > 0)
      {
        index = i;
        break;
      }
    }

    for (int i = 0; i < nums.size(); i++)
    {
      nums[i] = nums[i] * nums[i]; // squaring the numbers in an array
    }
    vector<int> numsDuplicate(nums.size());
    int numsIndex = -1;

    int i = index - 1;
    int j = index;
    while (i >= 0 && j < nums.size())
    {
      if (nums[i] < nums[j])
      {
        numsDuplicate[++numsIndex] = nums[i];
        i--;
      }
      else
      {
        numsDuplicate[++numsIndex] = nums[j];
        j++;
      }
    }

    while (j < nums.size())
    {
      numsDuplicate[++numsIndex] = nums[j];
      j++;
    }

    while (i >= 0)
    {
      numsDuplicate[++numsIndex] = nums[i];
      i--;
    }

    return numsDuplicate;
  }
};

int main()
{

  vector<int> v1 = {-1};
  Solution s1;
  v1 = s1.sortedSquares(v1);
  for (int i = 0; i < v1.size(); i++)
  {
    cout << v1[i] << " , ";
  }
}