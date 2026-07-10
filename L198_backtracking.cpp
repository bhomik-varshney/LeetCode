#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void helperFunc(vector<int> &nums, int currHouse, int &recentlyRobbed,int &money ,int n, int &res)
    {
        if(currHouse == n)
        {
            if(money > res)
            {
                res = money; 
            }
            return;
        }
        else
        {
            if(recentlyRobbed == currHouse -1)
            {
                // we can not rob it...
                helperFunc(nums,currHouse +1, recentlyRobbed,money,n,res);
                return;
            }
            else
            {
                // we can rob it or leave it...
                money += nums[currHouse];
                int temp = recentlyRobbed;
                recentlyRobbed = currHouse;
                helperFunc(nums,currHouse+1,recentlyRobbed,money,n,res);
                money -= nums[currHouse];
                recentlyRobbed = temp;
                helperFunc(nums,currHouse+1,recentlyRobbed,money,n,res);
                return;
            }
        }
    }

    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        int recentlyRobbed = -2;
        int currHouse = 0;
        int money = 0;
        int res = 0;
        helperFunc(nums,currHouse,recentlyRobbed,money,n,res);
        return res;
    }
};