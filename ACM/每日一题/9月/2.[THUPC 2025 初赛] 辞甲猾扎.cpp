#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e6+10;
const int MOD=998244353;

int n,k;
vector<int> edges[N];
vector<int> black_point;
vector<int> dis_black(N,1e18);
vector<int> dis_white(N,1e18);
vector<int> lim(N,1e18);
int ans=0;

void bfs()
{
    queue<int> q;
    for(auto& b: black_point)
    {
        dis_black[b]=0;
        q.push(b);
    }

    while(!q.empty())
    {
        int u=q.front(); q.pop();
        for(auto& v : edges[u])
        {
            if(dis_black[v]>dis_black[u]+1)
            {
                dis_black[v]=dis_black[u]+1;
                q.push(v);
            }
        }
    }
}

void dfs(int u,int f)
{
    dis_white[u]=1e18;
    lim[u]=dis_black[u];

    for(auto& v : edges[u])
    {
        if(v==f) continue;
        dfs(v,u);

        dis_white[u]=min(dis_white[u],dis_white[v]+1);
        lim[u]=min(lim[u],lim[v]-1);
    }

    if(dis_white[u]<=lim[u]) lim[u]=1e18;
    if(lim[u]==0)
    {
        ans++;
        dis_white[u]=0;
        lim[u]=1e18;
    }
}

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        int x; cin>>x;
        black_point.push_back(x);
    }

    for(int i=1;i<=n-1;i++)
    {
        int u,v; cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    bfs();

    dfs(1,0);
    if(lim[1]!=1e18) ans++;
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