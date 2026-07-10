#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  bool partitionsPalindrome(string s, vector<int> partitions)
  {
    if (partitions.size() != 1)
    {
      for (int i = 0; i < partitions.size(); i++)
      {

        if (i == 0)
        {
          string substring = s.substr(0, partitions[i]);
          bool res = isPalindrome(substring);
          if (res == false)
          {
            return false;
          }
        }
        else if (i == partitions.size() - 1)
        {
          string substring = s.substr(partitions[i - 1], partitions[i] - partitions[i - 1]);
          bool res = isPalindrome(substring);
          if (res == false)
          {
            return false;
          }
          string substring2 = s.substr(partitions[i], s.size() - partitions[i]);
          res = isPalindrome(substring2);
          if (res == false)
          {
            return false;
          }
        }
        else
        {
          string substring = s.substr(partitions[i - 1], partitions[i] - partitions[i - 1]);
          bool res = isPalindrome(substring);
          if (res == false)
          {
            return false;
          }
        }
      }
    }

    else
    {
      string substring = s.substr(0, partitions[0]);
      bool res = isPalindrome(substring);
      if (res == false)
      {
        return false;
      }
      substring = s.substr(partitions[0], s.size() - partitions[0]);
      res = isPalindrome(substring);
      if (res == false)
      {
        return false;
      }
    }

    return true;
  }
  bool isPalindrome(string s)
  {
    if (s.size() == 1 || s.size() == 0)
    {
      return true;
    }
    if (s[0] == s[s.size() - 1])
    {
      string new_string = s.substr(1, s.size() - 2);
      return isPalindrome(new_string);
    }
    else
    {
      return false;
    }
  }
  void helperFunc(string s, vector<int> partitions, int idx, vector<string> &temp, vector<vector<string>> &res)
  {
    if (s.size() != 0)
    {
      if (partitionsPalindrome(s, partitions) && idx >= s.size())
      {
        res.push_back(temp);
      }

      if (!partitionsPalindrome(s, partitions) && idx >= s.size())
      {
        return;
      }
      if (idx < s.size())
      {
        for (int i = idx; i < s.size(); i++)
        {

          // push the string into the temp...
          if (!partitions.empty())
          {
            temp.pop_back();
            int prevIdx = partitions[partitions.size() - 1];
            string substring = s.substr(prevIdx, i - prevIdx);
            temp.push_back(substring);
            // now after that string. that string must also be pushed...
            substring = s.substr(i, s.size() - i);
            temp.push_back(substring);
          }
          else
          {
            string substring = s.substr(0, i);
            temp.push_back(substring);
            substring = s.substr(i, s.size() - i);
            temp.push_back(substring);
          }

          partitions.push_back(i);
          helperFunc(s, partitions, i + 1, temp, res);
          // now pop that partitions... and pop two times in temp..
          temp.pop_back();
          temp.pop_back();
          partitions.pop_back();
        }
      }
    }
    else
    {
      temp.push_back(s);
      res.push_back(temp);
      return;
    }
  }
  vector<vector<string>> partition(string s)
  {
    vector<string> temp;
    vector<vector<string>> res;
    vector<int> partitions;
    int idx = 1;

    helperFunc(s, partitions, idx, temp, res);

    return res;
  }
};

int main()
{
  Solution s1;
  string s = "aab";
  vector<vector<string>> res = s1.partition(s);
  cout << res.size() << endl;
}