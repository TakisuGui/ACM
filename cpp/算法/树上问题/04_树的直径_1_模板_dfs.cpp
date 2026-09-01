#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=5e5+10;
const int MOD=998244353;

vector<pair<int,int>> edges[N];
vector<int> dis(N,0);
vector<int> last(N,-1);
int start,max_d=-1;

void dfs(int u,int f)
{
    last[u]=f;
    for(auto& [v,w] : edges[u])
    {
        if(v==f) continue;
        dis[v]=dis[u]+w;
        dfs(v,u);
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

    for(int i=1;i<=n;i++)
    {
        if(dis[i]>max_d)
        {
            start=i;
            max_d=dis[i];
        }
    }
    for(int i=1;i<=n;i++) dis[i]=0,max_d=-1;
    dfs(start,0);

    for(int i=1;i<=n;i++)
    {
        if(dis[i]>max_d)
        {
            start=i;
            max_d=dis[i];
        }
    }
    cout<<max_d<<endl;
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