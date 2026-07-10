#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  bool canConstruct(string ransomNote, string magazine)
  {
    unordered_map<char, int> forRansomNote;
    unordered_map<char, int> forMagazine;
    for (int i = 0; i < ransomNote.size(); i++)
    {
      forRansomNote[ransomNote[i]]++;
    }
    for (int i = 0; i < magazine.size(); i++)
    {
      forMagazine[magazine[i]]++;
    }

    for (auto i : forRansomNote)
    {
      if (i.second > forMagazine[i.first])
      {
        return false;
        break;
      }
    }

    return true;
  }
};

int main()
{
  Solution s1;
  cout << s1.canConstruct("aa", "aab");
}