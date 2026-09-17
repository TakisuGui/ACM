#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n; cin>>n;
    vector<ll> a(n+1);
    vector<ll> pre(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i]=pre[i-1]^a[i];
    }

    vector<ll> dp(n+1,1e18);
    dp[0]=0;

    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1]+a[i];
        ll min_dp=1e18;
        for(int j=i;j>=1;j--)
        {
            min_dp=min(min_dp,dp[j-1]);
            dp[i]=min(dp[i],min_dp+(pre[i]^pre[j-1]));
        }
    }

    cout<<dp[n]<<endl;
}



int main()
{
    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}