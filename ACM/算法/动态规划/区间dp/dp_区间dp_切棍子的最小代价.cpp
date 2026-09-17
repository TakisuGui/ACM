#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minCost(int n, vector<int>& cuts) {

        int m=cuts.size();
        sort(cuts.begin(),cuts.end());

        vector<int> arr(m+2);

        arr[0]=0;
        for(int i=1;i<=m;i++) arr[i]=cuts[i-1];
        arr[m+1]=n;

        vector<vector<int>> dp(m+2,vector<int>(m+2,0));
        
        // for(int i=1;i<=m;i++) dp[i][i]=arr[i+1]-arr[i-1];

        // for(int l=m-1,next;l>=1;l--)
        // {
        //     for(int r=l+1;r<=m;r++)
        //     {
        //         next=1e9;
        //         for(int k=l;k<=r;k++)
        //         {
        //             next=min(next,dp[l][k-1]+dp[k+1][r]);
        //         }
        //         dp[l][r]=arr[r+1]-arr[l-1]+next;
        //     }
        // }


        for(int len=1;len<=m;len++)
        {
            for(int l=1;len+l-1<=m;l++)
            {
                int r=l+len-1;

                int next=1e9;
                for(int k=l;k<=r;k++)
                {
                    int left=(k>l) ? dp[l][k-1] : 0;
                    int right=(k<r) ? dp[k+1][r] : 0;
                    next=min(next,left+right);
                }

                dp[l][r]=next+arr[r+1]-arr[l-1];
            }
        }

        return dp[1][m];
    }


};