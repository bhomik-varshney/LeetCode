#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int i = 0;
    int count = 1;
    for (int j = 1; j < nums.size(); j++)
    {

      if (nums[j] == nums[j - 1])
      {
        if (count == 1)
        {
          i++;
          nums[i] = nums[j];
          count = 0;
        }
      }
      else
      {
        i++;
        nums[i] = nums[j];
        count = 1;
      }
    }

    return i + 1;
  }
};

int main()
{
  vector<int> numbers = {1, 1, 1, 2, 2, 3};
  Solution s1;
  s1.removeDuplicates(numbers);
  for (int i = 0; i < numbers.size(); i++)
  {
    cout << numbers[i] << " , ";
  }
}