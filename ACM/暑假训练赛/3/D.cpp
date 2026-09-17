#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=5e5+10;
const int M=1e4+10;
const int MOD=1e9+7;

int fa[N];
int siz[N];

vector<pair<int,pair<int,int>>> edges(M);

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


void solve()
{
    int n,m,k; cin>>n>>m>>k;
    ini(n);

    for(int i=1;i<=m;i++)
    {
        int x,y,l; cin>>x>>y>>l;
        if(x>y) swap(x,y);

        edges[i]={l,{x,y}};
    }

    sort(edges.begin()+1,edges.begin()+1+m);
    int cost=0;
    int cnt=n;

    if(cnt<k)
    {
        cout<<"No Answer"<<endl;
        return;
    }

    for(int i=1;i<=m;i++)
    {
        if(cnt==k) break;

        int dx=edges[i].second.first,dy=edges[i].second.second;
        int v=edges[i].first;

        if(union_(dx,dy))
        {
            cost+=v;
            cnt--;
        }
    }

    if(cnt==k) cout<<cost<<endl;
    else cout<<"No Answer"<<endl;
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