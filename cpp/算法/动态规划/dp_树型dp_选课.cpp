#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=305;

vector<int> edges[N];
int score[N];
int dp[N][N];
int n,m;

void dfs(int u)
{
    dp[u][1]=score[u];

    for(auto v : edges[u])
    {
        dfs(v);

        for(int t=m;t>=1;t--)
        {
            for(int s=1;s<=t-1;s++)
            {
                dp[u][t]=max(dp[u][t],dp[u][t-s]+dp[v][s]);
            }
        }
    }
}


void solve()
{
    cin>>n>>m;
    m++;

    for(int i=1;i<=n;i++)
    {
        int k,s; cin>>k>>s;
        edges[k].push_back(i);
        score[i]=s;
    }

    memset(dp,0,sizeof dp);

    dfs(0);

    cout<<dp[0][m]<<endl;
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

