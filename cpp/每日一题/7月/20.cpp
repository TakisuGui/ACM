#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll

struct hero { ll cost; ll val; };
struct Pair { hero h1; hero h2; ll extra; };
int n,C,m;

void solve()
{
    cin>>n>>C>>m;
    vector<bool> in_pair(n+1,false);
    vector<hero> heros(n+1);
    vector<Pair> pairs(n+1);
    for(int i=1;i<=n;i++) cin>>heros[i].cost>>heros[i].val;
    for(int i=1;i<=m;i++)
    {
        int x,y,z; cin>>x>>y>>z;
        in_pair[x]=true; in_pair[y]=true;
        pairs[i]={heros[x],heros[y],z};
    }

    vector<hero> single_hero;
    for(int i=1;i<=n;i++)
    {
        if(!in_pair[i]) single_hero.push_back(heros[i]);
    }

    vector<vector<int>> dp(5,vector<int>(C+1,-1));
    dp[0][0]=0;


    for(auto& h : single_hero)
    {
        for(int k=3;k>=0;k--)
        {
            for(int c=C-h.cost;c>=0;c--)
            {
                if(dp[k][c]!=-1) dp[k+1][c+h.cost]=max(dp[k+1][c+h.cost],dp[k][c]+h.val);
            }
        }
    }

    for (int i=1; i<=m;i++)
    {
        auto& p=pairs[i];
        auto t_dp=dp;

        for(int k=3;k>=0;k--)
        {
            for(int c=C-p.h1.cost;c>=0;c--)
            {
                if(dp[k][c]!=-1) t_dp[k+1][c+p.h1.cost]=max(t_dp[k+1][c+p.h1.cost],dp[k][c]+p.h1.val);
            }
        }

        for(int k=3;k>=0;k--)
        {
            for(int c=C-p.h2.cost;c>=0;c--)
            {
                if(dp[k][c]!=-1) t_dp[k+1][c+p.h2.cost]=max(t_dp[k+1][c+p.h2.cost],dp[k][c]+p.h2.val);
            }
        }

        for(int k=2;k>=0;k--)
        {
            for(int c=C-p.h2.cost-p.h1.cost;c>=0;c--)
            {
                if(dp[k][c]!=-1) t_dp[k+2][c+p.h2.cost+p.h1.cost]=max(t_dp[k+2][c+p.h2.cost+p.h1.cost],dp[k][c]+p.h2.val+p.h1.val+p.extra);
            }
        }

        dp=move(t_dp);
    }

    ll ans=0;
    for(int k=0;k<=4;k++)
        for(int c=0;c<=C;c++)
            ans=max(ans,dp[k][c]);

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