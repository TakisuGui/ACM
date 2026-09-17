#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=5e2+10;
const int MOD=1e9+7;

vector<vector<bool>> vis(N,vector<bool>(N,false));
vector<int> du(N);
int n,m;

bool pass(int k)
{
    vector<int> d=du;
    vector<vector<bool>> cur(N,vector<bool>(N,false));

    for(int i=1; i<=n;i++)
        for(int j=1;j<=n;j++)
            cur[i][j]=vis[i][j];
        
    queue<pair<int,int>> q;
    int current_edges=m;
    int total_required=n*(n-1)/2;

    for(int i=1; i<=n;i++)
        for(int j=i+1;j<=n;j++)
    {
        if(!cur[i][j]&&d[i]+d[j]>=k)
        {
            cur[i][j]=cur[j][i]=true;
            q.push({i,j});
        }
    }
    while(!q.empty())
    {
        auto[u,v]=q.front(); q.pop();

        d[u]++; d[v]++;
        current_edges++;

        for(int e=1;e<=n;e++)
        {
            if(e==v||e==u) continue;

            if(!cur[e][u]||!cur[u][e])
            {
                if(d[e]+d[u]>=k)
                {
                    cur[e][u]=cur[u][e]=true;
                    q.push({e,u});
                }
            }
        }
        for(int e=1;e<=n;e++)
        {
            if(e==u||e==v) continue;

            if(!cur[e][v]||!cur[v][e])
            {
                if(d[e]+d[v]>=k)
                {
                    cur[e][v]=cur[v][e]=true;
                    q.push({e,v});
                }
            }
        }
    }
    return current_edges==total_required;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v; cin>>u>>v;
        vis[u][v]=vis[v][u]=true;
        du[v]++;
        du[u]++;
    }

    int l=0,r=2*n-2,k=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(pass(mid))
        {
            k=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<k<<endl;
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