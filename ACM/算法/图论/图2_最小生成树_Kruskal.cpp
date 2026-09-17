#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10;
const int M=2e5+10;

vector<pair<int,pair<int,int>>> edges(M);

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

void solve()
{
    int n,m; cin>>n>>m;
    ini(n);

    for(int i=1;i<=m;i++)
    {
        int x,y,z; cin>>x>>y>>z;
        if(x>y) swap(x,y);

        edges[i].first=z;
        edges[i].second.first=x;
        edges[i].second.second=y;
    }

    sort(edges.begin()+1,edges.begin()+1+m);

    ll ans=0;
    int cnt=0;

    for(int i=1;i<=m;i++)
    {
        int dx=edges[i].second.first,dy=edges[i].second.second;
        int v=edges[i].first;

        if(union_(dx,dy))
        {
            cnt++;
            ans+=v;
        }
    }

    if(cnt==n-1) cout<<ans<<endl;
    else cout<<"orz"<<endl;
}

int main()
{
    solve();

    return 0;
}