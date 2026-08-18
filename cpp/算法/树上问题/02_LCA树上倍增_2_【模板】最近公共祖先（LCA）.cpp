#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const int LIM=20;
#define endl "\n"

int power;
vector<int> edges[N];
int st[N][LIM];
int deep[N];
int n,m,s;

int log2(int n)
{
    int ans=0;
    while((1<<ans)<=(n>>1)) ans++;
    return ans;
}

void dfs(int u,int f)
{
    if(u==s) deep[u]=1;
    else deep[u]=deep[f]+1;

    st[u][0]=f;
    for(int p=1;p<=power;p++)
    {
        st[u][p]=st[st[u][p-1]][p-1];
    }

    for(auto& v : edges[u])
    {
        if(v==f) continue;
        dfs(v,u);
    }
}


int lca(int a,int b)
{
    if(deep[a]<deep[b]) swap(a,b);

    for(int p=power;p>=0;p--)
    {
        if(deep[st[a][p]]>=deep[b]) a=st[a][p];
    }

    if(a==b) return a;

    for(int p=power;p>=0;p--)
    {
        if(st[a][p]!=st[b][p])
        {
            a=st[a][p];
            b=st[b][p];
        }
    }
    return st[a][0];
}



void solve()
{
    cin>>n>>m>>s;
    power=log2(n);
    for(int i=1;i<n;i++)
    {
        int u,v; cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(s,0);

    while(m--)
    {
        int a,b; cin>>a>>b;
        cout<<lca(a,b)<<endl;
    }
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