#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
#define endl "\n"

vector<int> edges[N];
vector<int> fa(N);
vector<pair<int,int>> has[N];
vector<bool> vis(N,false);
vector<int> ans(N);
int n,m,s;

void ini(int n) {for(int i=1;i<=n+1;i++) fa[i]=i;};

int find_(int i)
{
    if(i!=fa[i]) fa[i]=find_(fa[i]);

    return fa[i];
}


void tarjan(int u,int f)
{
    vis[u]=true;

    for(auto& v : edges[u])
    {
        if(v==f) continue;
        tarjan(v,u);
        fa[v]=u;
    }

    for(auto& [v,id] : has[u])
    {
        if(vis[v]) ans[id]=find_(v);
    }
}


void solve()
{
    cin>>n>>m>>s;
    ini(n);
    for(int i=1;i<n;i++)
    {
        int u,v; cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for(int i=1;i<=m;i++)
    {
        int x,y; cin>>x>>y;
        has[x].push_back({y,i});
        has[y].push_back({x,i});
    }

    tarjan(s,0);

    for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
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