#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=2e5+10;

int fa[N];
int n,m;
string s;
bool has_A[N],has_B[N],has_C[N],has_D[N];

void ini(int n) {for(int i=1;i<=n;i++) fa[i]=i;};

int find_(int i)
{
    if(fa[i]!=i) fa[i]=find_(fa[i]);

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

struct Edges
{
    int u,v,id;
};

void solve()
{
    cin>>n>>m; ini(n);
    cin>>s; s=" "+s;

    vector<Edges> ab_edges,cd_edges,cross_edges;
    for(int i=0;i<m;i++)
    {
        int u,v; cin>>u>>v;
        char class_u=s[u],class_v=s[v];

        bool is_u_ab=(class_u=='A'||class_u=='B');
        bool is_v_ab=(class_v=='A'||class_v=='B');

        if(is_u_ab&&is_v_ab) ab_edges.push_back({u,v,i});
        else if(!is_u_ab&&!is_v_ab) cd_edges.push_back({u,v,i});
        else cross_edges.push_back({u,v,i});
    }

    vector<pair<int,int>> result_edges;

    for(auto & e: ab_edges)
    {
        if(union_(e.u,e.v)) result_edges.push_back({e.u,e.v});
    }
    for(auto & e: cd_edges)
    {
        if(union_(e.u,e.v)) result_edges.push_back({e.u,e.v});
    }

    for(int i=1;i<=n;i++)
    {
        int root=find_(i);
        if(s[i]=='A') has_A[root]=true;
        if(s[i]=='B') has_B[root]=true;
        if(s[i]=='C') has_C[root]=true;
        if(s[i]=='D') has_D[root]=true;
    }

    for(int i=1;i<=n;i++)
    {
        int root=find_(i);
        if(s[i]=='A'||s[i]=='B')
        {
            if(!has_A[root]||!has_B[root]) {cout<<"No"<<endl; return;}
        }
        else
        {
            if(!has_C[root]||!has_D[root]) {cout<<"No"<<endl; return;}
        }
    }

    for(auto & e:cross_edges)
    {
        if(union_(e.u,e.v)) result_edges.push_back({e.u,e.v});
    }

    if(result_edges.size()==n-1)
    {
        cout<<"Yes"<<endl;
        for(auto p : result_edges) cout<<p.first<<" "<<p.second<<endl;
    }
    else cout<<"No"<<endl;
}


int main()
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