#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
const int M=5e4+10;
const int LIM=21;
#define endl "\n"

int fa[N];
int siz[N];
int n,m,power;

vector<pair<int,pair<int,int>>> edges(M);
vector<int> tree[N];
vector<bool> vis(N,false);
vector<vector<int>> stjump(N<<1,vector<int>(LIM));
vector<vector<int>> stmin(N<<1,vector<int>(LIM,1e9));
vector<int> deep(N);
map<pair<int,int>,int> weight;

void ini(int n)
{
    for(int i=0;i<=n;i++)
    {
        fa[i]=i;
        siz[i]=1;
    }
}

int find_(int i)
{
    if(i!=fa[i]) fa[i]=find_(fa[i]);
    return fa[i];
}

bool union_(int x,int y)
{
    int fx=find_(x),fy=find_(y);
    if(fx!=fy)
    {
        if(siz[fx]>=siz[fy])
        {
            siz[fx]+=siz[fy];
            fa[fy]=fx;
        }
        else
        {
            siz[fy]+=siz[fx];
            fa[fx]=fy;
        }
        return true;
    }
    else return false;
}

int log2_(int i)
{
    int ans=0;
    while((1<<ans)<=(i>>1)) ans++;
    return ans;
}

void dfs(int u,int v,int f)
{
    vis[u]=true;
    if(f==0)
    {
        deep[u]=1;
        stjump[u][0]=u;
        stmin[u][0]=1e9;
    }
    else
    {
        deep[u]=deep[f]+1;
        stjump[u][0]=f;
        stmin[u][0]=v;
    }

    for(int p=1;p<=power;p++)
    {
        stjump[u][p]=stjump[stjump[u][p-1]][p-1];
        stmin[u][p]=min(stmin[u][p-1],stmin[stjump[u][p-1]][p-1]);
    }

    for(auto& e : tree[u])
    {
        if(vis[e]) continue;
        dfs(e,weight[{e,u}],u);
    }
}

int lca(int a,int b)
{
    if(find_(a)!=find_(b)) return -1;

    if(deep[a]<deep[b]) swap(a,b);

    int ans=1e9;
    for(int p=power;p>=0;p--)
    {
        if(deep[stjump[a][p]]>=deep[b])
        {
            ans=min(ans,stmin[a][p]);
            a=stjump[a][p];
        }
    }
    if(a==b) return ans;

    for(int p=power;p>=0;p--)
    {
        if(stjump[a][p]!=stjump[b][p])
        {
            ans=min({ans,stmin[a][p],stmin[b][p]});
            a=stjump[a][p];
            b=stjump[b][p];
        }
    }
    ans=min({ans,stmin[a][0],stmin[b][0]});
    return ans;
}

void solve()
{
    cin>>n>>m;
    power=log2_(n);
    ini(n);

    for(int i=1;i<=m;i++)
    {
        int x,y,z; cin>>x>>y>>z;
        if(x>y) swap(x,y);
        edges[i]={z,{x,y}};
    }
    sort(edges.begin()+1,edges.begin()+1+m);
    reverse(edges.begin()+1,edges.begin()+1+m);

    for(int i=1;i<=m;i++)
    {
        int dx=edges[i].second.first,dy=edges[i].second.second;
        int v=edges[i].first;

        if(union_(dx,dy))
        {
            tree[dx].push_back(dy);
            tree[dy].push_back(dx);
            weight[{dx,dy}]=v;
            weight[{dy,dx}]=v;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(!vis[i]) dfs(i,1e9,0);
    }

    int q; cin>>q;
    while(q--)
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