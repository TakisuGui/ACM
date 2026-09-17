#include<bits/stdc++.h>
using namespace std;


int MOD=1e9+7;
const int M=401;
const int N=23;
int mn,mx,len;

vector<vector<vector<int>>> dp(N,vector<vector<int>>(M,vector<int>(2,-1)));


class Solution {
public:

    void build() {
		for (int i = 0; i < len; i++) {
			for (int j = 0; j <= mx; j++) {
				dp[i][j][0] = -1;
				dp[i][j][1] = -1;
			}
		}
	}


    int count(string num1, string num2, int min_sum, int max_sum) 
    {
        mn=min_sum;
        mx=max_sum;
        len=num2.size();
        build();
        int ans=f(0,0,0,num2)%MOD;

        len=num1.size();
        build();
        ans=(ans-f(0,0,0,num1)+MOD)%MOD;

        if(check(num1)) ans=(ans+1)%MOD;

        return ans;
    }

    int f(int i,int sum,int free,string& num)
    {
        if(sum>mx) return 0;
        if(sum+(len-i)*9<mn) return 0;
        if(len==i) return 1;
        if(dp[i][sum][free]!=-1) return dp[i][sum][free];

        int cur=num[i]-'0';
        int ans=0;
        if(free==0)
        {
            for(int pick=0;pick<cur;pick++)
            {
                ans=(ans+f(i+1,sum+pick,1,num))%MOD;
            }
            ans=(ans+f(i+1,sum+cur,0,num))%MOD;
        }
        else
        {
            for(int pick=0;pick<=9;pick++)
            {
                ans=(ans+f(i+1,sum+pick,1,num))%MOD;
            }
        }

        dp[i][sum][free]=ans;
        return ans;
    }

    bool check(string& num)
    {
        int sum=0;
        for(auto i : num) sum+=(i-'0');

        return sum>=mn&&sum<=mx ? true : false;
    }
};