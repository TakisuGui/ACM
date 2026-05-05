#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countPalindromicSubsequences(string s) {
        const int MOD=1e9+7;
        int n=s.size();
        vector<int> last(256,-1);
        vector<int> left(n),right(n);

        for(int i=0;i<n;i++) ////每个位置左边最近相同字符的位置
        {
            left[i]=last[s[i]];
            last[s[i]]=i;
        }
        fill(last.begin(),last.end(),n); //初始化last
        for(int i=n-1;i>=0;i--) //每个位置右边最近相同字符的位置
        {
            right[i]=last[s[i]];
            last[s[i]]=i;
        }

        vector<vector<long long>> dp(n,vector<long long>(n,0));

        for(int i=0;i<n;i++) dp[i][i]=1;

        for(int len=2;len<=n;len++)
        {
            for(int i=0;i+len-1<n;i++)
            {
                int j=i+len-1;

                if(s[i]!=s[j]) dp[i][j]=(dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+MOD)%MOD;
                else
                {
                    int r=left[j];
                    int l=right[i];

                    if(l>r) dp[i][j]=(dp[i+1][j-1]*2+2)%MOD; //区间内部没有与 s[i] 相同的字符
                    else if(l==r) dp[i][j]=(dp[i+1][j-1]*2+1)%MOD;
                    else dp[i][j]=(dp[i+1][j-1]*2-dp[l+1][r-1]+MOD)%MOD;
                    
                }
            }
        }

        return dp[0][n-1];
    }
};