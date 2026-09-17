#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int sum=0;
        for(int num:nums) {sum+=num;}

        int n=nums.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2));

        for(int i=0;i<n-1;i++)
        {
            dp[i][i]=nums[i];
            dp[i][i+1]=max(nums[i],nums[i+1]);
        }
        dp[n-1][n-1]=nums[n-1];

        for(int l=n-3;l>=0;l--)
        {
            for(int r=l+2;r<n;r++)
            {
                dp[l][r]=max(nums[l]+min(dp[l+1][r-1],dp[l+2][r]),nums[r]+min(dp[l+1][r-1],dp[l][r-2]));
            }
        }
        

        int first=dp[0][n-1];
        int second=sum-first;

        return first>=second;
    }
};