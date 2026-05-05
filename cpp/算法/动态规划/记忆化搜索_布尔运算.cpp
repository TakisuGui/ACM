#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countEval(string s, int result) {
        int n=s.size();
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n,{-1,-1}));

        auto res=f(s,0,n-1,dp);

        return result ? res.second : res.first;
    }

    pair<int,int> f(string s ,int l,int r,vector<vector<pair<int,int>>>& dp)
    {
        if(dp[l][r].first!=-1&&dp[l][r].second!=-1) return {dp[l][r].first,dp[l][r].second};

        int f_cnt=0,t_cnt=0;
        if(l==r)
        {
            f_cnt= (s[l]=='0' ? 1 : 0);
            t_cnt= (s[r]=='0' ? 0 : 1);
        }
        else
        {
            for(int k=l+1,a,b,c,d;k<r;k+=2)
            {
               auto left=f(s,l,k-1,dp);
               auto right=f(s,k+1,r,dp);
               a=left.first;
               b=left.second;
               c=right.first;
               d=right.second;


                if(s[k]=='&')
                {
                    f_cnt+=a*c+a*d+c*b;
                    t_cnt+=b*d;
                }
                else if(s[k]=='|')
                {
                    f_cnt+=a*c;
                    t_cnt+=b*c+a*d+b*d;
                }
                else
                {
                    f_cnt+=a*c+b*d;
                    t_cnt+=a*d+c*b;
                }
            }
        }

        dp[l][r]={f_cnt,t_cnt};

        return{f_cnt,t_cnt};
    }
};