#include<bits/stdc++.h>
using namespace std;
const int MOD=1e6+7;

int n,m;

int main()
{
    cin>>n>>m;
    
    int dp[m+1];
    memset(dp,0,sizeof dp);
    dp[0]=1;

    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        for(int j=m;j>=0;j--)
        {
            int sum=0;
            for(int k=1;k<=x;k++)
            {
                if(k<=j) sum=(sum+dp[j-k])%MOD;
            }
            dp[j]=(dp[j]+sum)%MOD;
        }
    }

    cout<<dp[m]<<endl;

    return 0;
}