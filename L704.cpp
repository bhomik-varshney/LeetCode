#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    int res = -1;
    int low = 0;
    int high = nums.size() - 1;
    // the value for the answer must be provided in the given O(1) or O(N) time only...
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (nums[mid] == target)
      {
        res = mid;
        break;
      }
      else if (nums[mid] < target)
      {
        // means prev values will be less than target...
        low = mid + 1;
      }
      else
      {
        // next values are of no sense..
        high = mid - 1;
      }
    }

    return res;
  }
};

int main()
{
  vector<int> arr = {-1, 0, 3, 5, 9, 12};
  int target = 20;

  Solution s1;
  cout << s1.search(arr, target);
}