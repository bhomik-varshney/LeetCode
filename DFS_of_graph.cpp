#include <iostream>
using namespace std;

class Solution 
{
  public:
  bool alreadyInRes(vector<int> &res, int node)
  {
      for(int i =0;i<res.size();i++)
      {
          if(res[i] == node)
          {
              return true;
          }
      }
      return false;
  }
  
    void helperFunc(vector<vector<int>> & adj, int node, vector<int> &res)
    {
        if(alreadyInRes(res,node))
        {
            // no need to add that node to the res...
            return;
        }
        else
        {
            // add the node to the res...
            res.push_back(node);
            // find the neughbours of that node...
            for(int i =0;i<adj[node].size();i++)
            {
                helperFunc(adj,adj[node][i],res);
            }
            return;
        }
        
    }
  
    vector<int> dfs(vector<vector<int>>& adj) 
    {
        // Code here
        
        vector<int> res;
        helperFunc(adj,0,res); // starting from vertex 0....
        return res;
    }
};