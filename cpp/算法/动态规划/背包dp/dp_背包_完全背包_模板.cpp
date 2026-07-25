#include<bits/stdc++.h>
using namespace std;

int n,V;

int main()
{
    cin>>n>>V;
    int a[n+2],b[n+2];
    int dp[n+2][V+2];

    for(int i=1;i<=n;i++) cin>>b[i]>>a[i];

    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int j=1;j<=V;j++) dp[0][j]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=V;j++)
        {
            if(b[i]<=j) dp[i][j]=max(dp[i-1][j],dp[i][j-b[i]]+a[i]);
            else dp[i][j]=dp[i-1][j];
        }
    }

    cout<<dp[n][V]<<endl;

    memset(dp,-0x3f,sizeof dp);
    dp[0][0]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=V;j++)
        {
            if(b[i]<=j) dp[i][j]=max(dp[i-1][j],dp[i][j-b[i]]+a[i]);
            else dp[i][j]=dp[i-1][j];
        }
    }

    if(dp[n][V]>0) cout<<dp[n][V]<<endl;
    else cout<<0<<endl;

    return 0;
}