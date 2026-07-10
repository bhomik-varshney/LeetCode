#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
  int totalFruit(vector<int> &fruits)
  {
    int low = 0;
    int high = 0;
    int result = 0;
    map<int, int> count;
    if (fruits.size() != 0)
    {
      count[fruits[high]]++;
      while (low <= high && high < fruits.size())
      {

        if (count.size() <= 2)
        {
          if ((high - low + 1) > result)
          {
            result = (high - low + 1);
          }
          high++;
          if (high < fruits.size())
          {
            count[fruits[high]]++;
          }
        }
        else
        {
          count[fruits[low]]--;
          if (count[fruits[low]] == 0)
          {
            count.erase(fruits[low]);
          }
          low++;
        }
      }
      return result;
    }
    else
    {
      return -1;
    }
  }
};

int main()
{
  Solution s1;
  vector<int> fruits = {0};
  cout << s1.totalFruit(fruits);
}