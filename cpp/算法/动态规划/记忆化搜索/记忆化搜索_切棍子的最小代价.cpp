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

        vector<vector<int>> dp(m+2,vector<int>(m+2,-1));
        
        return f(arr,1,m,dp);
    }

    int f(vector<int>& arr,int l,int r,vector<vector<int>>& dp)
    {
        if(l>r) return 0;
        if(l==r) return arr[r+1]-arr[l-1];
        if(dp[l][r]!=-1) return dp[l][r];

        int ans=1e9;

        for(int k=l;k<=r;k++)
        {
            ans=min(ans,f(arr,l,k-1,dp)+f(arr,k+1,r,dp));
        }
        ans+=arr[r+1]-arr[l-1];
        dp[l][r]=ans;

        return ans;
    }
};