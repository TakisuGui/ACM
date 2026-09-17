#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int mod=1e9+7;
const int N=1e5+10;

ll dp[N][2];
vector<int> edges[N];

void dfs(int u,int fa)
{
    dp[u][0]=dp[u][1]=1;
    for(auto v:edges[u])
    {
        if(v==fa) continue;
        dfs(v,u);
        dp[u][0]=(dp[u][0]*dp[v][1])%mod;   //0白,1红
        dp[u][1]=(dp[u][1]*(dp[v][0]+dp[v][1]))%mod;
    }
}

void solve()
{
    int n; cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v; cin>>u>>v;
        edges[v].push_back(u);
        edges[u].push_back(v);
    }

    dfs(1,0);

    cout<<(dp[1][0]%mod+dp[1][1]%mod)%mod<<endl;
}

int main()
{
    solve();

    return 0;
}

