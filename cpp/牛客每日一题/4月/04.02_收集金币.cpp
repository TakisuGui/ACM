#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
const int INF=1e9;

int a[N][N],cost[N][N],dp[N][N];


int main()
{
    int n,m; cin>>n>>m;;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];

    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=-INF;
            cost[i][j]=INF;
        }
    int t; cin>>t;
    while(t--)
    {
        int x,y,v; cin>>x>>y>>v;
        cost[x][y]=v;
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(cost[i][j]<=i+j-2) a[i][j]=-INF*2;

    dp[1][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];

    int ans=-1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ans=max(ans,dp[i][j]);

    cout<<ans<<endl;

    return 0;
}