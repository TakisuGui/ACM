#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=5e5+10;
const int MOD=1e7+7;
const long long INF=1e18;

int n,m,k;

int get_min(int l)
{
    if(l==INF) return INF;
    int t=((l+k-1)/k)*k;

    if(t%2==l%2) return t;
    else
    {
        if(k%2!=0) return t+k;
        else return INF;
    }
}

void solve()
{
    cin>>n>>m>>k;
    vector<vector<int>> edge(n+1);

    for(int i=1;i<=m;i++)
    {
        int v,u; cin>>v>>u;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    vector<vector<int>> dis(n+1,vector<int>(2,INF));
    queue<pair<int,int>> q;
    dis[1][0]=0;
    q.push({1,0});

    while(!q.empty())
    {
        auto [u,p]=q.front(); q.pop();

        for(auto v : edge[u])
        {
            int next_p=p^1;
            if(dis[v][next_p]==INF)
            {
                dis[v][next_p]=dis[u][p]+1;
                q.push({v,next_p});
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        int ans=INF;

        int even=get_min(dis[i][0]);
        int odd=get_min(dis[i][1]);
        ans=min({ans,even,odd});

        if(ans==INF) cout<<-1<<" ";
        else cout<<ans<<" ";
    }
    cout<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}