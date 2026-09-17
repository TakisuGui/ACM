#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=2e4+10;
const int MOD=998244353;

vector<int> edges[N];
vector<int> siz(N+1,0);
int ans=2e4+10,ans_id=-1;
int n; 

void dfs(int u,int f)
{
    for(auto& v : edges[u])
    {
        if(v==f) continue;
        dfs(v,u);
        siz[u]+=siz[v];
    }
    siz[u]+=1;

    int cur=-1;
    for(auto& v : edges[u])
    {
        if(v==f) cur=max(cur,n-siz[u]);
        else cur=max(cur,siz[v]);
    }

    if(cur<ans)
    {
        ans=cur;
        ans_id=u;
    }
}
    
void solve()
{
    cin>>n;
    for (int i=0;i<=n;i++) edges[i].clear(),siz[i]=0;
    ans=2e4+10,ans_id=-1;

    for(int i=1;i<=n-1;i++)
    {
        int v,u; cin>>v>>u;
        edges[v].push_back(u);
        edges[u].push_back(v);
    }
    dfs(1,0);
    
    cout<<ans_id<<" "<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}