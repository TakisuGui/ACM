#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=998244353;

vector<int> edges[N];
vector<int> siz(N+1,0);
int ans=1e18;vector<int> ans_id;
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
        ans_id={u};
    }
    else if(cur==ans) ans_id.push_back(u);
}

int find_(int u,int f)
{
    for(auto& v : edges[u])
    {
        if(v==f) continue;
        return find_(v,u);
    }
    return u;
}
    
void solve()
{
    cin>>n;
    for (int i=0;i<=n;i++) edges[i].clear(),siz[i]=0;
    ans=1e18,ans_id={};

    for(int i=1;i<=n-1;i++)
    {
        int v,u; cin>>v>>u;
        edges[v].push_back(u);
        edges[u].push_back(v);
    }
    dfs(1,0);
    
    if(ans_id.size()==1)
    {
        cout<<ans_id[0]<<" "<<edges[ans_id[0]][0]<<endl;
        cout<<ans_id[0]<<" "<<edges[ans_id[0]][0]<<endl;
    }
    else
    {
        int child=find_(ans_id[1],ans_id[0]);
        cout<<child<<" "<<edges[child][0]<<endl;
        cout<<ans_id[0]<<" "<<child<<endl;
    }
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