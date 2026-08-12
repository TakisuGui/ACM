#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int MOD=998244353;

void solve()
{
    int n,m; cin>>n>>m;
    int L=2*n-1;
    vector<bool> pass(L+1,false);
    bool bad=false;

    for(int i=0;i<m;i++)
    {
        int a; cin>>a;
        if(a>L) bad=true;
        else pass[a]=true;
    }

    if(bad)
    {
        cout<<0<<endl;
        return;
    }

    vector<vector<int>> dp(L+1, vector<int>(n+1,0));
    dp[0][0]=1;

    for(int i=1;i<=L;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(pass[i])
            {
                if(j>0&&i<=j*2-1) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=0;
            }
            else
            {
                dp[i][j]=dp[i-1][j];

                if(j>0&&i<=j*2-1) dp[i][j]+=dp[i-1][j-1];

                if(dp[i][j]>=MOD) dp[i][j]-=MOD;
            }

        }
    }

    cout<<dp[L][n]<<endl;
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