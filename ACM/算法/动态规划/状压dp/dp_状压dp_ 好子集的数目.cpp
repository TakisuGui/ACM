#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
        static const int MAXV=30;
        static const int LIMIT=1<<10;
        static const int MOD=1e9+7;

        // 质数顺序: 29, 23, 19, 17, 13, 11, 7, 5, 3, 2
        // 位索引:    9,  8,  7,  6,  5,  4, 3, 2, 1, 0

        static constexpr int own[MAXV+1]=
        {
            0b0000000000, // 0
            0b0000000000, // 1
            0b0000000001, // 2
            0b0000000010, // 3
            0b0000000000, // 4
            0b0000000100, // 5
            0b0000000011, // 6
            0b0000001000, // 7
            0b0000000000, // 8
            0b0000000000, // 9
            0b0000000101, // 10
            0b0000010000, // 11
            0b0000000000, // 12
            0b0000100000, // 13
            0b0000001001, // 14
            0b0000000110, // 15
            0b0000000000, // 16
            0b0001000000, // 17
            0b0000000000, // 18
            0b0010000000, // 19
            0b0000000000, // 20
            0b0000001010, // 21
            0b0000010001, // 22
            0b0100000000, // 23
            0b0000000000, // 24
            0b0000000000, // 25
            0b0000100001, // 26
            0b0000000000, // 27
            0b0000000000, // 28
            0b1000000000, // 29
            0b0000000111  // 30
        };

    int numberOfGoodSubsets(vector<int>& nums)
    {
        vector<int> cnt(MAXV+1,0);
        for(int num : nums) cnt[num]++;

        vector<vector<int>> dp(MAXV+1,vector<int>(LIMIT,-1));

        int ans=0;

        for(int i=1;i<LIMIT;i++) ans=(ans+f(MAXV,i,cnt,dp))%MOD;
        
        return ans;
    }

    int f(int i,int s,vector<int>& cnt,vector<vector<int>>& dp)
    {
        if(dp[i][s]!=-1) return dp[i][s];

        int ans=0;
        if(i==1)
        {
            if(s==0)
            {
                ans=1;
                for(int j=0;j<cnt[1];j++) ans=(ans<<1)%MOD;
            }
        }
        else
        {
            ans=f(i-1,s,cnt,dp);
            int cur=own[i];
            int times=cnt[i];

            if(cur!=0&&times!=0&&(s&cur)==cur)
            {
                ans=((long long)f(i-1,s^cur,cnt,dp)*times+ans)%MOD;
            }
        }

        dp[i][s]=ans;
        return ans;
    }
};