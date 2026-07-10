#include <iostream>
using namespace std;

class Solution
{
public:
  int size(int n)
  {
    int result = 1;
    while (n / 10 != 0)
    {
      n = n / 10;
      result++;
    }
    return result;
  }

  bool isHappy(int n)
  {
    while (true)
    {
      int result = 0;
      int temp = n;
      for (int i = 0; i < size(n); i++)
      {
        int val = temp % 10;
        result += val * val;
        temp = temp / 10;
      }
      n = result;
      if (n == 1 || n == 7)
      {
        return true;
        break;
      }
      if (n / 10 == 0)
      {
        return false;
        break;
      }
    }
  }
};

int main()
{
  Solution s1;
  cout << s1.isHappy(1111111);
}