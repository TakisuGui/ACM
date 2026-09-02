#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=1e5+10;
const int MOD=1e9+7;

void solve()
{
    int n,m; cin>>n>>m;
    vector<int> a(m+1);
    for(int i=1;i<=m;i++) cin>>a[i];

    vector<vector<bool>> dp(m+1,vector<bool>(n,false));
    dp[0][0]=true;

    for(int i=1;i<=m;i++)
    {
        int step=a[i]%n;

        for(int j=0;j<n;j++)
        {
            if(dp[i-1][j])
            {
                dp[i][(j+step)%n]=true;
                dp[i][((j-step)%n+n)%n]=true;
            }
        }
    }

    cout<<(dp[m][0] ? "YES" : "NO")<<endl;
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
