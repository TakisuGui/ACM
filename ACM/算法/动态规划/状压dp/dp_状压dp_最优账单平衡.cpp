#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    static const int MAXN=13;

    int minTransfers(vector<vector<int>>& transactions)
    {
        vector<int> balance(MAXN,0);
        for(auto& v: transactions)
        {
            balance[v[0]]-=v[2];
            balance[v[1]]+=v[2];
        }

        vector<int> debt;
        for(int num : balance)
        {
            if(num!=0) debt.push_back(num);
        }

        int n=debt.size();
        if(n==0) return 0;

        vector<int> dp(1<<n,-1);
        
        return n-f(debt,(1<<n)-1,0,n,dp);
    }

    int f(vector<int>& debt,int status,int sum,int n,vector<int>& dp)
    {
        if(dp[status]!=-1) return dp[status];

        int ans=0;
        if( (status&(status-1)) !=0 ) //集合中不只一个元素
        {
            if(sum==0)
            {
                for(int i=0;i<n;i++)
                {
                    if( (status&(1<<i)) !=0 )
                    {
                        ans=f(debt,status^(1<<i),sum-debt[i],n,dp)+1;
                        break;
                    }
                }
            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    if( (status&(1<<i)) !=0 )
                    {
                        ans=max(ans,f(debt,status^(1<<i),sum-debt[i],n,dp));
                    }
                }
            }
        }

        dp[status]=ans;
        return ans;
    }

};