#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<char> charsFromNum(char i)
  {
    vector<char> v2 = {'a', 'b', 'c'};
    vector<char> v3 = {'d', 'e', 'f'};
    vector<char> v4 = {'g', 'h', 'i'};
    vector<char> v5 = {'j', 'k', 'l'};
    vector<char> v6 = {'m', 'n', 'o'};
    vector<char> v7 = {'p', 'q', 'r', 's'};
    vector<char> v8 = {'t', 'u', 'v'};
    vector<char> v9 = {'w', 'x', 'y', 'z'};
    if (i == '2')
    {
      return v2;
    }
    else if (i == '3')
    {
      return v3;
    }
    else if (i == '4')
    {
      return v4;
    }
    else if (i == '5')
    {
      return v5;
    }

    else if (i == '6')
    {
      return v6;
    }

    else if (i == '7')
    {
      return v7;
    }

    else if (i == '8')
    {
      return v8;
    }

    else
    {
      return v9;
    }
  }
  void helperFunc(string &digits, int size, string &temp, vector<string> &res)
  {
    if (temp.size() == size)
    {
      res.push_back(temp);
      return;
    }
    if (temp.size() < size)
    {
      vector<char> v1 = charsFromNum(digits[0]);
      for (int i = 0; i < v1.size(); i++)
      {
        temp.push_back(v1[i]); // after pushing that calculate all the outcomes possible...
        string new_digits = digits.substr(1, digits.size() - 1);
        helperFunc(new_digits, size, temp, res);
        temp.pop_back();
      }
    }
  }
  vector<string> letterCombinations(string digits)
  {
    vector<string> res;
    string temp;
    int size = digits.size();
    helperFunc(digits, size, temp, res);
    return res;
  }
};

int main()
{
  Solution s1;
  string digits = "2";
  vector<string> res = s1.letterCombinations(digits);
  cout << res.size() << endl;
}