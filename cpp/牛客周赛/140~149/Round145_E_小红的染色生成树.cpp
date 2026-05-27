#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e5+10;   
const int M=2e5+10;

vector<pair<int,pair<int,int>>> edges(M);
vector<pair<int,int>> ans_edges;  // 存储最终选中的边
int n,m;
int fa[N];

void ini(int n) {for(int i=1;i<=n;i++) fa[i]=i;}
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
        fa[fx]=fy;
        return true;
    }
    else return false;
}

bool try_build(int a,int b)
{
    ini(n);
    ans_edges.clear();
    bool used_a=false,used_b=false;

    for(int i=1;i<=m;i++)
    {
        int color=edges[i].first;
        int u=edges[i].second.second;
        int v=edges[i].second.first;

        if(color==a)
        {
            if(union_(u,v))
            {
                ans_edges.push_back({u,v});
                used_a=true;
                if(ans_edges.size()==n-1)break;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        int color=edges[i].first;
        int u=edges[i].second.second;
        int v=edges[i].second.first;

        if(color==b)
        {
            if(union_(u,v))
            {
                ans_edges.push_back({u,v});
                used_b=true;
                if(ans_edges.size()==n-1)break;
            }
        }
    }

    if(ans_edges.size()!=n-1) return false;
    return used_a&&used_b;
}

void solve()
{   
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int u,v,color; cin>>u>>v>>color;
        edges[i]={color,{u,v}};
    }

    int color_pairs[3][2]={{0,1},{0,2},{1,2}};

    for(auto u:color_pairs)
    {
        int a=u[0],b=u[1];

        if(try_build(a,b))
        {
            for(auto e : ans_edges) cout<<e.first<<" "<<e.second<<endl;
            return;
        }
        if(try_build(b,a))
        {
            for(auto e : ans_edges) cout<<e.first<<" "<<e.second<<endl;
            return;
        }
    }

    cout<<-1<<endl;
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