#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<long long>> dp(n,vector<long long>(n,0));

        for(int l=n-3;l>=0;l--)
        {
            for(int r=l+2;r<n;r++)
            {
                dp[l][r]=1e18;
                for(int m=l+1;m<r;m++)
                {
                    dp[l][r]=min(dp[l][r],dp[l][m]+dp[m][r]+values[l]*values[r]*values[m]);               
                }
            }
        }

        return dp[0][n-1];
    }
};