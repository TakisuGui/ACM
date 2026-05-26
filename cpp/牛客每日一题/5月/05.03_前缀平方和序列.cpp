#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int MOD=1e9+7;

void solve()
{
    int n,x; cin>>n>>x;
    vector<int> sq;
    for(int i=1;i*i<=x;i++) sq.push_back(i*i);
    int cnt=sq.size();

    vector<vector<int>> dp(n+1,vector<int>(cnt,0));
    for(int j=0;j<cnt;j++) dp[1][j]=1;

    for(int len=2;len<=n;len++)
    {
        vector<int> pref(cnt,0);
        pref[0]=dp[len-1][0];

        for(int j=1;j<cnt;j++) pref[j]=(pref[j-1]+dp[len-1][j])%MOD;

        for(int j=1;j<cnt;j++) dp[len][j]=pref[j-1];
    }

    int ans=0;
    for(int j=0;j<cnt;j++) ans=(ans+dp[n][j])%MOD;

    cout<<ans<<endl;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}