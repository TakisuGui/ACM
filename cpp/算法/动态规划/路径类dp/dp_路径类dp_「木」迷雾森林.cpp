#include<bits/stdc++.h>
using namespace std;

int m,n;
const int MOD=2333;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>m>>n;
    int a[m+2][n+2];
    int dp[m+2][n+2];
    memset(dp,0,sizeof dp);

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }

    for(int i=m;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==m&&j==1)
            {
                dp[i][j]=1%MOD;
                continue;
            }

            if(!a[i][j]) dp[i][j]=(dp[i+1][j]+dp[i][j-1])%MOD;
            else dp[i][j]=0;
        }
    }

    cout<<dp[1][n]%MOD<<endl;

    return 0;
}