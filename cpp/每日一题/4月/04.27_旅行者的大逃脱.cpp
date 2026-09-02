#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=5e2+10;
const int MOD=998244353;

ll dp[105][N][N];
bool is_bad[105][N][N];

void solve()
{
    int n,m,q,k; cin>>n>>m>>q>>k;
    for(int t=0;t<=k;t++) 
        for(int i=0;i<=n;i++) 
            for(int j=0; j<=m;j++) 
            {
                dp[t][i][j]=0;
                is_bad[t][i][j]=false;
            }
        

    for(int i=0;i<q;i++)
    {
        int x,y,t; cin>>x>>y>>t;

        for(int ti=t;ti<=k;ti++) is_bad[ti][x][y]=true;
    }

    dp[1][1][1]=1;

    for(int t=2;t<=k;t++)
    {
        for(int i=1;i<=n;i++)
        {
            ll row_sum=0;
            for(int j=1;j<=m;j++)
            {
                if(is_bad[t-1][i][j]) row_sum=0;
                else row_sum=(row_sum+dp[t-1][i][j])%MOD;

                if (!is_bad[t][i][j])
                {
                    // 我们要的是从左边跳过来的,所以要减去当前格 row_sum 刚加进去的dp[t-1][i][j]
                    ll from_left=(row_sum-dp[t-1][i][j]+MOD)%MOD;
                    dp[t][i][j]=(dp[t][i][j]+from_left)%MOD;
                }
            }
        }


        for(int j=1;j<=m;j++)
        {
            ll col_sum=0;
            for(int i=1;i<=n;i++)
            {
                if(is_bad[t-1][i][j]) col_sum=0;
                else col_sum=(col_sum+dp[t-1][i][j])%MOD;
                if (!is_bad[t][i][j])
                {
                    ll from_top=(col_sum-dp[t-1][i][j]+MOD) % MOD;
                    dp[t][i][j]=(dp[t][i][j]+from_top)%MOD;
                }
            }
        }
    }

    
    ll total=0;
    int min_time=-1;
    for(int t=1;t<=k;t++)
    {
        if(dp[t][n][m]>0)
        {
            if(min_time==-1) min_time=t-1;
            total=(total+dp[t][n][m])%MOD;
        }
    }

    if(min_time==-1) cout<<-1<<endl;
    else cout<<total<<" "<<min_time<<endl;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}