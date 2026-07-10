// we must do it by using BFS, but here is the different approach using DFS
#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
  public:
    int DFS(vector<vector<int>> &adj,int node, int des,vector<bool> &visited)
    {
        int minDis = INT_MAX;
        visited[node] = true;
        if(node == des)
        {
            minDis = 0;
            visited[node] = false;
            return minDis;
        }
        
        for(int i =0;i<adj[node].size();i++)
        {
            int neighbour = adj[node][i];
            if(!visited[neighbour])
            {
                int DistFromNeigh = DFS(adj,neighbour,des,visited);
                if(DistFromNeigh != INT_MAX && DistFromNeigh + 1 < minDis)
                {
                    minDis = DistFromNeigh + 1;
                }
            }
        }
        visited[node] = false;
        return minDis;
    }
    
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) 
    {
        vector<int> res;
       
        vector<vector<int>> adj(V);
        for(int i =0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i =0;i<V;i++)
        {
            vector<bool> visited(V,false);
            int des = i;
            int dis = DFS(adj,src,des,visited);
            if(dis == INT_MAX)
            {
                res.push_back(-1);
            }
            else
            {
                res.push_back(dis);
            }
        }
        return res;
    }
};