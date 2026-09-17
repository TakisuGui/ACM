#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n+2);
        arr[0]=1,arr[n+1]=1;
        for(int i=1;i<=n;i++) arr[i]=nums[i-1];

        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));

        return f(arr,1,n,dp);
    }

    //一定有 arr[l-1]没爆
    //一定有 arr[r+1]没爆
    int f(vector<int>& arr,int l,int r,vector<vector<int>>& dp)
    {
        if(dp[l][r]!=-1) return dp[l][r];

        int ans;
        if(l==r) ans=arr[l-1]*arr[l]*arr[r+1];
        else
        {
            ans=max(arr[l-1]*arr[l]*arr[r+1]+f(arr,l+1,r,dp),arr[r+1]*arr[r]*arr[l-1]+f(arr,l,r-1,dp));
            
            for(int k=l+1;k<r;k++) ans=max(ans,arr[l-1]*arr[k]*arr[r+1]+f(arr,l,k-1,dp)+f(arr,k+1,r,dp));
        }

        dp[l][r]=ans;
        return ans;
    }
};