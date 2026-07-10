#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void segregate0and1(vector<int> &arr)
  {
    // code here
    int i = 0;
    int j = arr.size() - 1;
    while (j > i)
    {
      if (arr[j] == 0 && arr[i] == 1)
      {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
      }
      else if (arr[j] == 0 && arr[i] != 1)
      {
        i++;
      }
      else if (arr[j] != 0 && arr[i] == 1)
      {
        j--;
      }
      else
      {
        i++;
        j--;
      }
    }
  }
};

int main()
{
  vector<int> numbers = {0, 1, 0, 0, 1, 1, 0, 1, 0, 1};
  Solution s1;
  s1.segregate0and1(numbers);
  for (int i = 0; i < numbers.size(); i++)
  {
    cout << numbers[i] << " , ";
  }
}