#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;
    while (mid <= high)
    {
      if (nums[mid] == 0)
      {
        swap(nums[low], nums[mid]);
        low++;
        mid++;
      }
      else if (nums[mid] == 1)
      {
        mid++;
      }
      else
      {
        swap(nums[high], nums[mid]);
        high--;
      }
    }
  }
};

int main()
{
  vector<int> v = {2, 0, 2, 1, 1, 0};
  Solution s1;
  s1.sortColors(v);

  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " , ";
  }
}