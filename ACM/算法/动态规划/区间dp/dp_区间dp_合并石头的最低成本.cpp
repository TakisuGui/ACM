#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n=stones.size();
        if((n-1)%(k-1)!=0) return -1;

        vector<int> pre(n+1,0);
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]+stones[i-1];
        
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int len=2;len<=n;len++)
        {
            for(int l=0;len+l-1<n;l++)
            {
                int r=l+len-1;
                int best=1e9;

                for(int m=l;m<r;m+=(k-1))
                {
                    best=min(best,dp[l][m]+dp[m+1][r]);
                }

                if((r-l)%(k-1)==0) best+=pre[r+1]-pre[l];

                dp[l][r]=best;
            }
        }

        return dp[0][n-1];
    }
};