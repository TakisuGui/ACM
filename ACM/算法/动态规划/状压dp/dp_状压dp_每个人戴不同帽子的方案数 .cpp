#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int MOD=1e9+7;
    int numberWays(vector<vector<int>>& arr)
    {
        int m=0;
        for(auto person : arr)
        {
            for(int hat : person) m=max(m,hat);
        }

        int n=arr.size();
        // 1 ~ m 帽子,能满足哪些人,状态信息
        vector<int> hats(m+1,0);
        for(int i=0;i<n;i++)
        {
            for(auto hat : arr[i]) hats[hat] |= 1<<i;
        }

        vector<vector<int>> dp(m+1,vector<int>(1<<n,-1));

        return f(hats,m,n,1,0,dp);
    }
                                        // i:来到了什么颜色的帽子
    int f(vector<int>& hats,int m,int n,int i,int status,vector<vector<int>>& dp)
    {                                        //没满足状态就是0,满足了状态就是1
        if(status==(1<<n)-1) return 1;
        if(i==m+1) return 0;
        if(dp[i][status]!=-1) return dp[i][status];

        int ans=f(hats,m,n,i+1,status,dp);
        int cur=hats[i];

        for(int p=0;p<n;p++)
        {
            if( (cur&(1<<p))!=0 && ((status&(1<<p))==0) )
            {
                ans=(ans+f(hats,m,n,i+1,status|(1<<p),dp))%MOD;
            }
        }

        dp[i][status]=ans;
        return ans;
    }
};