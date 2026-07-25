#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int strangePrinter(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,1e9));

        dp[n-1][n-1]=1;
        for(int i=0;i<n-1;i++)
        {
            dp[i][i]=1;
            dp[i][i+1]=( (s[i]==s[i+1]) ? 1 : 2 );
        }

        for(int len=3;len<=n;len++)
        {
            for(int l=0;l+len-1<=n-1;l++)
            {
                int r=l+len-1;

                if(s[l]==s[r]) dp[l][r]=min(dp[l][r-1],dp[l+1][r]);
                else
                {
                    int ans=1e9;
                    for(int m=l;m<r;m++) ans=min(ans,dp[l][m]+dp[m+1][r]);

                    dp[l][r]=ans;
                }
            }
        }

        return dp[0][n-1];
    }
};