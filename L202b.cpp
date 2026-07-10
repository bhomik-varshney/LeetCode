#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int squareValue(int n) // we can use slow and fast pointer in the happy number
  {
    int result = 0;
    while (n != 0)
    {
      int val = n % 10;
      result += pow(val, 2);
      n = n / 10;
    }
    return result;
  }
  bool isHappy(int n)
  {
    int slow = n;
    int fast = n;
    while (true)
    {
      slow = squareValue(slow);
      fast = squareValue(squareValue(fast));
      cout << "slow : " << slow << "fast : " << fast << endl;
      if (slow == fast)
      {
        break;
      }
    }

    if (fast == 1)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

int main()
{
  Solution s1;
  cout << s1.isHappy(2);
}