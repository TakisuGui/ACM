#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=2e5+10;
const int MOD=998244353;

vector<pair<int,int>> edges[N];
vector<int> dis(N,0);
vector<int> last(N,-1);
vector<bool> diameterPath(N,false);
int start,max_d=-1,end_;

void dfs(int u,int f)
{
    last[u]=f;
    for(auto& [v,w] : edges[u])
    {
        if(v==f) continue;
        dis[v]=dis[u]+w;
        dfs(v,u);
    }
}

int maxDistanceExceptDiameter(int u,int f,int c)
{
    int ans=c;
    for(auto& [v,w] : edges[u])
    {
        if(v!=f&&!diameterPath[v]) ans=max(ans,maxDistanceExceptDiameter(v,u,c+w));
    }
    return ans;
}

void solve()
{
    int n; cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v,w; cin>>u>>v>>w;
        edges[u].push_back({v,w});
        edges[v].push_back({u,w});
    }
    dfs(1,0);

    for(int i=1;i<=n;i++)
    {
        if(dis[i]>max_d)
        {
            start=i;
            max_d=dis[i];
        }
    }
    for(int i=1;i<=n;i++) dis[i]=0,max_d=-1;
    dfs(start,0);

    for(int i=1;i<=n;i++)
    {
        if(dis[i]>max_d)
        {
            end_=i;
            max_d=dis[i];
        }
    }
    cout<<max_d<<endl;
    for(int i=end_;i!=0;i=last[i]) diameterPath[i]=true;

    int maxdis; int l=start; int r=end_;
    for(int i=last[end_];i!=start;i=last[i])
    {
        maxdis=maxDistanceExceptDiameter(i,0,0);
        if(maxdis==max_d-dis[i]) r=i;
        if(maxdis==dis[i]&&l==start) l=i;
    }

    int commonedges=0;
    if(l==r) commonedges=0;
    else
    {
        commonedges=1;
        for(int i=last[r];i!=l;i=last[i]) commonedges++;
    }
    cout<<commonedges<<endl;
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