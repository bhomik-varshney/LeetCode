#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool inText2(string text2,string subsequence)
    {
        int i =0;
        int j =0;

        while(j < subsequence.size() && i < text2.size())
        {
            if(text2[i] == subsequence[j])
            {
                // just increase both i and j..
                i++;
                j++;
            }
            else
            {
                // if they are not equal, means.. just increase i only..
                i++;
            }
        }

        if(j == subsequence.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int helperFunc(string &text1,string &text2,int idx,string currSequence)
    {
        if(idx == text1.size())
        {
            return 0; // as no subsequence of length could be found...
        }

        // check if we take the character at idx , will it increase our answer...

        // now make case if the idx is taken, and not taken..
        string newString = currSequence;
        newString.push_back(text1[idx]);
        if(inText2(text2,newString))
        {
            // means we can take it...
            int taken = 1 + helperFunc(text1,text2,idx+1,newString);
            int notTaken = helperFunc(text1,text2,idx+1,currSequence);
            return max(taken,notTaken);
        }
        else
        {
            return helperFunc(text1,text2,idx+1,currSequence);
        }        
    }



    int longestCommonSubsequence(string text1, string text2) 
    {
        string currSequence;
        return helperFunc(text1,text2,0,currSequence);
    }
};