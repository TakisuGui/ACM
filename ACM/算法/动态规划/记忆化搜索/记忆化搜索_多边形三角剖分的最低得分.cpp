#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    long long f(vector<int>& values,int l,int r,vector<vector<long long>> &dp)
    {
        if(dp[l][r]!=-1) return dp[l][r];
        long long ans=1e18;

        if(l==r||l==r-1) ans=0;
        else
        {
            for(int m=l+1;m<r;m++)
            {
                ans=min(ans,f(values,l,m,dp)+f(values,m,r,dp)+values[l]*values[r]*values[m]);
            }
        }

        dp[l][r]=ans;
        return ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<long long>> dp(n,vector<long long>(n,-1));

        return f(values,0,n-1,dp);
    }
};