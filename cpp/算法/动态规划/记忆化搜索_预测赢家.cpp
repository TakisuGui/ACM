#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int f(vector<int>& nums,int l,int r,vector<vector<int>>& dp) 
    {
        if(dp[l][r]!=-1) return dp[l][r];

        int ans;
        if(l==r) ans=nums[l];
        else if(l==r-1) ans=max(nums[l],nums[r]);
        else
        {
            int p1=nums[l]+min(f(nums,l+1,r-1,dp),f(nums,l+2,r,dp));
            int p2=nums[r]+min(f(nums,l,r-2,dp),f(nums,l+1,r-1,dp));
            ans=max(p1,p2);
        }

        dp[l][r]=ans;
        return ans;
    }


    bool predictTheWinner(vector<int>& nums) {
        int sum=0;
        for(int num:nums) {sum+=num;}

        int n=nums.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2));

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dp[i][j]=-1;
        

        int first=f(nums,0,n-1,dp);
        int second=sum-first;

        return first>=second;
    }
};