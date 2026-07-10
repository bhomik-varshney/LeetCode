#include <iostream>
#include <vector>
#include <vector>
using namespace std;

struct cmp
{
  bool operator()(pair<int, int> &a, pair<int, int> &b)
  {
    if (a.second > b.second)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

class Solution
{
public:
  int differ(string s1, string s2)
  {
    int diff = 0;
    for (int i = 0; i < s1.size(); i++)
    {
      if (s1[i] != s2[i])
      {
        diff++;
      }
    }
    return diff;
  }

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
    // make an adjacency list for it...
    vector<vector<int>> adj(wordList.size() + 2);
    for (int i = 0; i < wordList.size(); i++)
    {
      string connection = wordList[i];
      if (differ(beginWord, connection) == 1)
      {
        adj[0].push_back(i + 1);
        adj[i + 1].push_back(0);
      }
    }

    for (int i = 0; i < wordList.size(); i++)
    {
      string subject = wordList[i];
      for (int j = 0; j < wordList.size(); j++)
      {
        string connection = wordList[j];
        if (differ(subject, connection) == 1)
        {
          adj[i + 1].push_back(j + 1);
        }
      }
    }

    // now do for the end word...
    for (int i = 0; i < wordList.size(); i++)
    {
      string connection = wordList[i];
      if (differ(endWord, connection) == 1)
      {
        adj[wordList.size() + 1].push_back(i + 1);
        adj[i + 1].push_back(wordList.size() + 1);
      }
    }

    if (differ(beginWord, endWord) == 1)
    {
      adj[0].push_back(wordList.size() + 1);
      adj[wordList.size() + 1].push_back(0);
    }
    // list is ready....

    vector<int> dis(wordList.size() + 2, INT_MAX);
    // use dijsktra's for that..
    // priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> heap; // {val,dis}
    // heap.push({0,0});
    // while(!heap.empty())
    // {
    //     int nodeIdx = heap.top().first;
    //     int d = heap.top().second;
    //     heap.pop();

    //     if(dis[nodeIdx] > d)
    //     {
    //         dis[nodeIdx] = d;

    //         // find its neighbours having distance 1 only...
    //         for(int i =0;i<adj[nodeIdx].size();i++)
    //         {
    //             int neighIdx = adj[nodeIdx][i];
    //             // now we have nodeIdx and neighIdx...
    //             if(dis[neighIdx] > dis[nodeIdx] + 1)
    //             {
    //                 heap.push({neighIdx,dis[nodeIdx] + 1});
    //             }
    //         }

    //     }
    // }

    // use BFS as well to do so;

    dis[0] = 0;
    queue<int> q;
    vector<bool> visited(wordList.size() + 2, false);
    q.push(0);
    visited[0] = true;
    while (!q.empty())
    {
      int node = q.front();
      q.pop();

      // check for the neighbour....
      for (int i = 0; i < adj[node].size(); i++)
      {
        int neigh = adj[node][i];
        if (!visited[neigh])
        {
          dis[neigh] = dis[node] + 1;
          q.push(neigh);
          visited[neigh] = true;
        }
      }
    }

    if (dis[wordList.size() + 1] == INT_MAX || !inWordList(wordList, endWord))
    {
      return 0;
    }
    else
    {
      return dis[wordList.size() + 1] + 1;
    }
  }
};