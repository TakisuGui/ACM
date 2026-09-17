#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e9+7;

int fa[N];
int siz[N];

void ini(int n) { for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;}

int find_(int i)
{
    if(fa[i]!=i) fa[i]=find_(fa[i]);
    return fa[i];
}

void union_(int x,int y)
{
    int fx=find_(x),fy=find_(y);

    if(fx!=fy)
    {
        if(siz[fx]>=siz[fy])
        {
            fa[fy]=fx;
            siz[fx]+=siz[fy];
        }
        else
        {
            siz[fy]+=siz[fx];
            fa[fx]=fy;
        }
    }
}



void solve()
{
    int n,k; cin>>n>>k;
    vector<int> sign(k+1);
    vector<pair<int,int>>edges(n+1);
    vector<int> neighbor[n+1];
    vector<bool> is_sign(n+1,false);
    ini(n);

    // 输入数据
    for(int i=1;i<=k;i++) 
    {
        cin>>sign[i];
        is_sign[sign[i]]=true;
    }
    for(int i=1;i<=n-1;i++)
    {
        int u,v; cin>>u>>v;
        if(u>v) swap(u,v);

        neighbor[u].push_back(v);
        neighbor[v].push_back(u);
        edges[i].first=u;
        edges[i].second=v;
    }


    // 建立连通块
    for(int i=1;i<=n-1;i++)
    {
        int u=edges[i].first,v=edges[i].second;
        if(is_sign[u]&&is_sign[v]) union_(u,v);
    }


    // 统计每个连通块连接到未标记节点的边数
    vector<int> boundary_cnt(n+1,0);
    for(int i=1;i<=k;i++)
    {
        int u=sign[i];
        int root=find_(u);

        for(auto v : neighbor[u])
        {
            if(!is_sign[v]) boundary_cnt[root]++;
        }
    }


    // 计算 连通块个数 & 方案数
    int cost=0;
    int way=1;

    for(int i=1;i<=k;i++)
    {
        int u=sign[i];
        if(u==find_(u)) // 联通快个数 等于 满足(u==find_(u))个数
        {
            cost++;
            way=(way*boundary_cnt[u])%MOD;
        }
    }

    cout<<cost<<" "<<way<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}
