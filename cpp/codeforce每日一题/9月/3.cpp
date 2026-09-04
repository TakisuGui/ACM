#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=2e5+10;
const int MOD=1e7+7;

vector<int> edges[N];
vector<int> d(N,0);
vector<bool> vis(N,false);
vector<int> fa(N);

void dfs(int u,int f)
{
    fa[u]=f;
    d[u]=d[f]+1;
    for(auto& v : edges[u])
    {
        if(v==f) continue;
        dfs(v,u);
    }
}

void solve()
{
    int n; cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int v,u; cin>>v>>u;
        edges[v].push_back(u);
        edges[u].push_back(v);
    }
    dfs(1,0);

    priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> pq;
    for(int i=1;i<=n;i++)
    {
        if(d[i]<=3) vis[i]=true;
        else pq.push({d[i],i});
    }

    int ans=0;
    while(!pq.empty())
    {
        auto [dis,id]=pq.top(); pq.pop();
        if(vis[id]) continue;

        int f=fa[id]; vis[f]=true;
        ans++;
        for(auto& v : edges[f])
        {
            vis[v]=true;
        }
    }

    cout<<ans<<endl;
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