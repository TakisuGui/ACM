#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=3e3+10;

int fa[N];
int a[N];
int sz[N];

void ini(int n) {for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;}
int find_(int u)
{
    if(u!=fa[u]) fa[u]=find_(fa[u]);

    return fa[u];
}
bool union_(int x,int y)
{
    int fx=find_(x),fy=find_(y);

    if(fx!=fy)
    {
        if(sz[fx]>=sz[fy])
        {
            fa[fy]=fx;
            sz[fx]+=sz[fy];
        }
        return true;
    }
    else return false;
}

void solve()
{
    int n; cin>>n;
    ini(n);
    int m=n*(n-1)/2;
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<pair<int,pair<int,int>>>edges(m+1);
    int has=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int cost;
            if((i+j)%2==0) cost=a[(i+j)/2]*2;
            else cost=(a[(i+j)/2]+a[(i+j+1)/2]);

            ++has;
            edges[has].first=cost;
            edges[has].second.first=i;
            edges[has].second.second=j;
        }
    }

    sort(edges.begin()+1,edges.begin()+has+1);
    int ans=0;
    int cnt=0;

    for(int i=1;i<=has;i++)
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
    else cout<<"-1"<<endl;
}


signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}