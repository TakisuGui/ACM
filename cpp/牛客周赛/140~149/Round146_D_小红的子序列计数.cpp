#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;
const int MOD=998244353;

void solve()
{   
    int n; string s;
    cin>>n>>s; s=' '+s;

    vector<vector<int>> dp(n+1,vector<int>(3,0));
    int ans=0;

    for(int i=1;i<=n;i++)
    {
        int x=s[i]-'0';
        int rem=x%3;

        for(int j=0;j<3;j++) dp[i][j]=dp[i-1][j];

        for(int j=0;j<3;j++)
        {
            int next=(j+rem)%3;
            dp[i][next]=(dp[i][next]+dp[i-1][j])%MOD;
        }

        dp[i][rem]=(dp[i][rem]+1)%MOD;

        if(x%2==0)
        {
            int tar=(3-rem)%3;

            ans=(ans+dp[i-1][tar])%MOD;
            if(rem==0) ans=(ans+1)%MOD;
        }
    }

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