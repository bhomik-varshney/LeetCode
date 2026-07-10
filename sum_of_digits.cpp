#include <iostream>
using namespace std;

class Solution
{
public:
  int sumOfDigits(int n)
  {
    // code here
    int x = n / 10;
    if (x == 0) // if single digit number
    {
      return n;
    }
    int digit = n % 10;
    int res = sumOfDigits(x); // jaadu wala answer...
    return res + digit;
  }
};