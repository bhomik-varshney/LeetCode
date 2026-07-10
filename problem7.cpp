#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    sort(nums.begin(), nums.end()); // this will sort the exisiting nums vector
    vector<vector<int>> result;
    for (int k = 0; k < nums.size() - 1; k++)
    {
      if (k != 0 && nums[k] == nums[k - 1])
      {
        continue;
      }
      else
      {
        int i = k + 1;
        int j = nums.size() - 1;
        int target = 0;
        int newTarget = target - nums[k];
        if (i < nums.size() && j >= 0)
        {
          while (j > i)
          {
            int sum = nums[i] + nums[j];
            if (sum < newTarget)
            {
              i++;
            }
            else if (sum > newTarget)
            {
              j--;
            }
            else
            {
              vector<int> val = {nums[i], nums[j], nums[k]};
              result.push_back(val);
              i++;
              j--;
              while (i < nums.size() && nums[i] == nums[i - 1])
              {
                i++;
              }
              while (j < nums.size() - 1 && j >= 0 && nums[j] == nums[j + 1])
              {
                j--;
              }
            }
          }
        }
      }
    }

    return result;
  }
};

int main()
{
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  Solution s1;
  vector<vector<int>> triplets = s1.threeSum(nums);
  for (int i = 0; i < triplets.size(); i++)
  {
    cout << triplets[i][0] << " , " << triplets[i][1] << " , " << triplets[i][2] << endl;
  }
}