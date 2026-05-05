#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int N,H;

int main()
{
    cin>>N>>H;

    int m[N+1],v[N+1];
    ll dp[N+1][H+1];

    for(int i=1;i<=N;i++) cin>>m[i]>>v[i];

    memset(dp,0x3f,sizeof dp);
    dp[0][0]=0;

    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<=H;j++)
        {
            dp[i][j]=dp[i-1][j];

            int need=max(0,j-m[i]);
            dp[i][j]=min(dp[i][j],dp[i][need]+v[i]);
        }
    }

    cout<<dp[N][H]<<endl;

    return 0;
}