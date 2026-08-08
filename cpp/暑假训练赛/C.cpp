#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=101;
const int MOD=1e7+7;
const int INF=1e18;


void solve()
{
    int m,x; cin>>m>>x;
    vector<int> c(m+1),h(m+1);
    ll total_h=0;
    for(int i=1;i<=m;i++)
    {
        cin>>c[i]>>h[i];
        total_h+=h[i];
    }

    vector<vector<int>> dp(m+1,vector<int>(total_h+1,INF));
    dp[0][0]=0,dp[1][0]=0;

    for(int i=1;i<=m;i++)
    {
        int v=(i-1)*x;
        for(int j=0;j<=total_h;j++)
        {
            dp[i][j]=dp[i-1][j];

            if(j>=h[i]&&dp[i-1][j-h[i]]+c[i]<=v) 
            dp[i][j]=min(dp[i][j],dp[i-1][j-h[i]]+c[i]);
        }
    }

    int ans=-1;
    for(int i=0;i<=total_h;i++)
    {
        if(dp[m][i]!=INF) ans=max(ans,i);
    }
    cout<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}