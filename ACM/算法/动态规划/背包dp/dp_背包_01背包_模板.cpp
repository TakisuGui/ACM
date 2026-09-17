#include<bits/stdc++.h>
using namespace std;

int n,V;

int main()
{
    cin>>n>>V;
    int dp[n+5][V+5];
    int a[n+1];
    int b[n+1];

    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    for(int j=0;j<=V;j++) dp[0][j]=0;
    for(int i=0;i<=n;i++) dp[i][0]=0;
       

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=V;j++)
        {
            if(j-a[i]>=0)
            dp[i][j]=max(dp[i-1][j],b[i]+dp[i-1][j-a[i]]);
            else
            dp[i][j]=dp[i-1][j];
        }
    }

    cout<<dp[n][V]<<endl;


    memset(dp,-0x3f,sizeof dp);
    dp[0][0]=0;
    for(int i=0;i<=n;i++) dp[i][0]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=V;j++)
        {
            if(j-a[i]>=0)
            dp[i][j]=max(dp[i-1][j],b[i]+dp[i-1][j-a[i]]);
            else
            dp[i][j]=dp[i-1][j];
        }
    }

    if(dp[n][V]>0) cout<<dp[n][V]<<endl;
    else cout<<"0"<<endl;

    return 0;
}