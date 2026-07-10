#include <iostream>
#include <vector>
using namespace std;

// class Solution
// {

// };

int main()
{

  vector<int> numbers = {3, 3, 3, 4, 4, 4, 6, 7, 8, 8, 9};
  int position = 0;
  for (int j = 1; j < numbers.size(); j++)
  {

    if (numbers[j] != numbers[j - 1])
    {
      position++;
      numbers[position] = numbers[j];
    }
  }

  for (int i = 0; i <= position; i++)
  {
    cout << numbers[i] << " , ";
  }
}