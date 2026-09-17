#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=3e5+10;
const int MOD=998244353;

vector<int> edges[N];

int d[N];
int fa[N];
int n,m,q; 
int max_d=-1,max_id;

void ini(int n)
{
    for(int i=0;i<=n;i++)
    {
        fa[i]=i;
    }
}
int find_(int i)
{
    if(i!=fa[i]) fa[i]=find_(fa[i]);
    return fa[i];
}

void dfs(int u,int f,int depth)
{
    if(depth>max_d)
    {
        max_d=depth;
        max_id=u;
    }
    for(auto& v : edges[u])
    {
        if(v==f) continue;
        dfs(v,u,depth+1);
    }
}

int get_d(int u)
{
    max_d=-1;
    dfs(u,0,0);
    max_d=-1;
    dfs(max_id,0,0);
    
    return max_d;
}

void solve()
{
    cin>>n>>m>>q;
    ini(n);
    for(int i=1;i<=m;i++)
    {
        int u,v; cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
        
        int fu=find_(u),fv=find_(v);
        if(fu!=fv) fa[fu]=fv;
    }

    for(int i=1;i<=n;i++)
    {
        int fi=find_(i);
        if(i==fi) d[fi]=get_d(i);
    }
    
    while(q--)
    {
        int op; cin>>op;
        if(op==1)
        {
            int x; cin>>x;
            cout<<d[find_(x)]<<endl;
        }
        else
        {
            int x,y; cin>>x>>y; 
            int fx=find_(x),fy=find_(y);
            if(fx!=fy)
            {
                int d1=d[fx],d2=d[fy];
                fa[fx]=fy;
                d[fy]=max({(d1+1)/2+(d2+1)/2+1,d1,d2});
            }
        }
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