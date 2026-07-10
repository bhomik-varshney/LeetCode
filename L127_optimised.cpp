#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
  bool inWordList(vector<string> &wordList, string word)
  {
    for (int i = 0; i < wordList.size(); i++)
    {
      if (wordList[i] == word)
      {
        return true;
      }
    }
    return false;
  }

  int ladderLength(string beginWord, string endWord, vector<string> &wordList)
  {
    if (!inWordList(wordList, endWord))
    {
      return 0;
    }
    else
    {
      unordered_map<string, int> map;
      map[beginWord]++;
      for (int i = 0; i < wordList.size(); i++)
      {
        map[wordList[i]]++;
      }

      // now make a queue and add it beginWord into it...
      queue<pair<string, int>> q;
      q.push({beginWord, 1});
      map.erase(beginWord);
      vector<char> charArray = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
      while (!q.empty())
      {
        string s = q.front().first;
        int val = q.front().second;
        q.pop();
        if (s == endWord)
        {
          return val;
        }
        // check all its possibility...
        for (int i = 0; i < s.size(); i++)
        {
          char c = s[i];
          for (int j = 0; j < charArray.size(); j++)
          {
            // change the string s into changed one..
            if (charArray[j] != c)
            {
              // change it with new one...
              s[i] = charArray[j];
              // check this is in unordermap or not...
              if (map.find(s) != map.end())
              {
                // push it into the queue and remove from the map
                q.push({s, val + 1});
                map.erase(s);
              }
            }
          }
          s[i] = c; // back to normal
        }
      }
      return 0;
    }
  }
};