#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &numbers, int target)
  {
    int i = 0;
    int j = numbers.size() - 1;
    vector<int> result(2);
    while (j > i)
    {
      int sum = numbers[i] + numbers[j];
      if (sum == target)
      {
        result[0] = i + 1;
        result[1] = j + 1;
        return result;
      }
      else if (sum < target)
      {
        i++;
      }
      else
      {
        j--;
      }
    }
    result[0] = -1;
    result[1] = -1;
    return result;
  }
};

int main()
{
  Solution s1;
  vector<int> sample = {2, 3, 4};
  vector<int> answer = s1.twoSum(sample, 6);
  cout << "[" << answer[0] << ", " << answer[1] << "]" << endl;
}