#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=101;
const int MOD=1e7+7;
const int INF=1e18;

vector<int> a(N);
vector<vector<int>> dp(N,vector<int>(N,0));

void solve()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int len=3;len<=n;len++)
    {
        for(int l=1;l+len-1<=n;l++)
        {
            int r=l+len-1;
            dp[l][r]=INF;

            for(int k=l+1;k<r;k++)
            {
                dp[l][r]=min(dp[l][r],dp[l][k]+dp[k][r]+a[r]*a[k]*a[l]);
            }
        }
    }
    
    cout<<dp[1][n]<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}
