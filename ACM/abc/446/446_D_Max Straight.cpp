#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;

int n;
ll a[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    unordered_map<ll,ll> dp;
    ll ans=0;

    for(int i=1;i<=n;i++)
    {
        dp[a[i]]=dp[a[i]-1]+1;
        ans=max(ans,dp[a[i]]);
    }

    cout<<ans<<endl;

    return 0;
}