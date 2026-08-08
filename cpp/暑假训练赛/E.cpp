#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=998244353;
const int INF=1e18;


void solve()
{
    int n; cin>>n;
    string s; cin>>s;

    int full=(1<<n)-1;
    vector<int> dp((1<<n),0);
    dp[0]=1;

    for(int mask=0;mask<=full;mask++)
    {
        char pre='$';
        for(int j=0;j<n;j++)
        {
            if((mask>>j) & 1)
            {
                if(pre!=s[j]) dp[mask]=(dp[mask]+dp[mask^(1<<j)])%MOD;
                pre=s[j];
            }
            
        }
    }
    cout<<dp[full]<<endl;
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