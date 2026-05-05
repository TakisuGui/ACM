#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n+2);
        arr[0]=1,arr[n+1]=1;
        for(int i=1;i<=n;i++) arr[i]=nums[i-1];

        vector<vector<int>> dp(n+2,vector<int>(n+2,0));

        for(int i=1;i<=n;i++) dp[i][i]=arr[i-1]*arr[i]*arr[i+1];

        for(int len=2;len<=n;len++)
        {
            for(int l=1;l+len-1<=n;l++)
            {
                int r=l+len-1;

                for(int k=l;k<=r;k++)
                {
                    dp[l][r]=max(dp[l][r],dp[l][k-1]+dp[k+1][r]+arr[l-1]*arr[k]*arr[r+1]);
                }
            }
        }

        return dp[1][n];
    }

};