#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=2e5+10;
const int M=1e4+10;
const int MOD=1e9+7;

int fa[N];
vector<bool> vis(N,false);

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

void union_(int x,int y)
{
    int fx=find_(x),fy=find_(y);
    if(fx!=fy)
    {
       if(fx>fy) fa[fy]=fx;
       else fa[fx]=fy;
    }
}


void solve()
{
    int n,m; cin>>n>>m;
    ini(n);

    for(int i=1;i<=m;i++)
    {
        int a,b; cin>>a>>b;
        union_(a,b);
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        vis[i]=true;

        int max_=find_(i);
        for(int j=i+1;j<=max_;j++)
        {
            if(vis[j]) continue;
            vis[j]=true;
            
            if(find_(j)!=max_)
            {
                ans++;
                union_(i,j);
                max_=find_(i);
            }
        }
    }
    cout<<ans<<endl;
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