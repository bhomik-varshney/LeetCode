#include <iostream>
using namespace std;

class Solution {
public:

    int climbStairs(int n) 
    {
        if(n == 1 || n == 2)
        {
            return n;   
        }
        int f1 = 1;
        int f2 = 2;
        for(int i = n-3 ;i >= 0;i--)
        {
            int ans = f1+f2;
            f1 = f2;
            f2 = ans;
        }

        return f2;
        
    }
};