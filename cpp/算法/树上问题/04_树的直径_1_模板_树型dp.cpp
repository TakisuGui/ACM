#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=5e5+10;
const int MOD=998244353;

vector<pair<int,int>> edges[N];
vector<int> dis(N,0); // 从u开始必须往下走，能走出的最大距离，可以不选任何边
vector<int> ans(N,0); // 路径必须包含点u的情况下，最大路径和

void dfs(int u,int f)
{
    for(auto& [v,w] : edges[u])
    {
        if(v==f) continue;
        dfs(v,u);
        ans[u]=max(ans[u],dis[u]+dis[v]+w);
        dis[u]=max(dis[u],dis[v]+w);
    }
}

void solve()
{
    int n; cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v,w; cin>>u>>v>>w;
        edges[u].push_back({v,w});
        edges[v].push_back({u,w});
    }
    dfs(1,0);

    int pass=-1;
    for(auto& x : ans) pass=max(pass,x);
    cout<<pass<<endl;
    
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