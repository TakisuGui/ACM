#include<bits/stdc++.h>
using namespace std;

int n,t;

int main()
{
    cin>>n>>t;
    int x[n+1],m[n+1],v[n+1];
    for(int i=1;i<=n;i++) cin>>x[i]>>m[i]>>v[i];

    int dp[n+1][t+1];
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int j=0;j<=t;j++) dp[0][j]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=t;j++)
        {
            dp[i][j]=dp[i-1][j];

            for(int k=1;k<=x[i];k++)
            {
                if(k*m[i]<=j) dp[i][j]=max(dp[i][j],dp[i-1][j-k*m[i]]+k*v[i]);
                else break;
            }
        }
    }

    cout<<dp[n][t]<<endl;

    return 0;
}