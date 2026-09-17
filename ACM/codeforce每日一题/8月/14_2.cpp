#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e18;
const int MOD=1e7+7;


void solve()
{
    int n; cin>>n;
    vector<vector<int>> dp(n+1,vector<int>(n+1,N));
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        a[x]++;
    }

    dp[0][0]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=a[i];j<=n;j++) dp[i][j-a[i]]=min(dp[i][j-a[i]],dp[i-1][j]);

        if(a[i])
        for(int j=0;j<n;j++) dp[i][j+1]=min(dp[i][j+1],dp[i-1][j]+1);
    }
    cout<<*min_element(dp[n].begin(),dp[n].end())<<endl;
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