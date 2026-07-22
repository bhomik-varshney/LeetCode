#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        vector<vector<vector<int>>> mem(3,vector<vector<int>>(3,vector<int>(prices.size()+1,0)));   // trans -> id -> idx

        for(int i =1;i<3;i++)
        {
            for(int j =1;j<3;j++)
            {
                for(int k = prices.size()-1; k >= 0;k--)
                {
                    if(j == 1)
                    {
                        mem[i][j][k] = max(mem[i-1][j+1][k+1]+prices[k],mem[i][j][k+1]);
                    }
                    else
                    {
                        mem[i][j][k] = max(mem[i][j-1][k+1]-prices[k],mem[i][j][k+1]);
                    }
                }
            }
        }

        return mem[2][2][0];
    }
};