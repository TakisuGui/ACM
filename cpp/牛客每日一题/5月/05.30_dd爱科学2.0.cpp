#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e6+10;

int dp[N][26];

void solve()
{
    int n; string s; cin>>n>>s; s=" "+s;

    for(int j=0;j<26;j++) dp[1][j]=abs((s[1]-'A')-j);

    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<26;j++)
        {
            int best=1e9;

            for(int k=0;k<=j;k++) best=min(best,dp[i-1][k]);

            dp[i][j]=best+abs((s[i]-'A')-j);
        }
    }

    int ans=dp[n][0];
    for(int i=1;i<26;i++) ans=min(ans,dp[n][i]);

    cout<<ans<<endl;
}


signed main()
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