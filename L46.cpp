#include <iostream>

using namespace std;

class Solution
{
public:
  void helperFunc(vector<int> &nums, int size, vector<int> &temp, vector<vector<int>> &res)
  {
    if (temp.size() == size)
    {
      res.push_back(temp);
      return;
    }
    if (temp.size() < size)
    {
      for (int i = 0; i < nums.size(); i++)
      {
        int val = nums[i];
        temp.push_back(val); // push back that value into the temp...
        vector<int> new_nums;
        for (int j = 0; j < nums.size(); j++)
        {
          if (nums[j] != val)
          {
            new_nums.push_back(nums[j]); // cause that is already being taken into account...
          }
        }
        helperFunc(new_nums, size, temp, res);
        temp.pop_back();
      }
    }
  }
  vector<vector<int>> permute(vector<int> &nums)
  {
    int size = nums.size();
    vector<int> temp;
    vector<vector<int>> res;
    helperFunc(nums, size, temp, res);
    return res;
  }
};

int main()
{
  Solution s1;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> res = s1.permute(nums);
  cout << res.size() << endl;
}