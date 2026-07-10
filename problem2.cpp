#include <iostream>
#include <vector>
using namespace std;

// class Solution
// {

// };

int main()
{

  vector<int> numbers = {3, 3, 3, 4, 4, 4, 6, 7, 8, 8, 9};
  int size = numbers.size();
  int position = 0;
  for (int i = 0; i < size; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (numbers[i] == numbers[j])
      {
        j++;
      }
      if (numbers[i] != numbers[j])
      {
        numbers[++position] = numbers[j];
        i = j;
      }
    }
  }

  for (int i = 0; i <= position; i++)
  {
    cout << numbers[i] << " , ";
  }
}