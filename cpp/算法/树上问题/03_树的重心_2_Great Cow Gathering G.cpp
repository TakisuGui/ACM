#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=998244353;

vector<pair<int,int>> edges[N];
vector<int> w(N+1,0);
vector<int> siz(N+1,0);
int ans=1e18,ans_id=-1;
int n,total_weight=0;

void dfs1(int u,int f)
{
    for(auto& [v,l] : edges[u])
    {
        if(v==f) continue;
        dfs1(v,u);
        siz[u]+=siz[v];
    }

    int cur=-1;
    for(auto& [v,l] : edges[u])
    {
        if(v==f) cur=max(cur,total_weight-siz[u]);
        else cur=max(cur,siz[v]);
    }

    if(cur<ans)
    {
        ans=cur;
        ans_id=u;
    }
}

int dfs2(int u,int f)
{
    int total=0;
    for(auto& [v,l] : edges[u])
    {
        if(v==f) continue;
        total+=l*siz[v]+dfs2(v,u);
    }
    return total;
}
    
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i],siz[i]=w[i],total_weight+=siz[i];

    for(int i=1;i<=n-1;i++)
    {
        int v,u,l; cin>>v>>u>>l;
        edges[v].push_back({u,l});
        edges[u].push_back({v,l});
    }
    dfs1(1,0);
    for (int i=0;i<=n;i++) siz[i]=w[i];
    dfs1(ans_id,0);
    
    int total=dfs2(ans_id,0);
    cout<<total<<endl;
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