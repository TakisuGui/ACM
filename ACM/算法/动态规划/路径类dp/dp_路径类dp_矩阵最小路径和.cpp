#include<bits/stdc++.h>
using namespace std;

const int N=510;
int n,m;
int dp[N][N];

int main()
{
    cin>>n>>m;
    memset(dp,0x3f,sizeof dp);
    dp[0][1]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int x;cin>>x;
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+x;
        }
    }

    cout<<dp[n][m]<<endl;

    return 0;
}