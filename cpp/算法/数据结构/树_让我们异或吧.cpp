#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

vector<pair<int,int>> edges[N];
int dist[N];
bool vis[N];

void dfs(int u,int cur)
{
    dist[u]=cur;
    vis[u]=true;

    for(auto&[v,w]:edges[u])
    {
        if(!vis[v])
        {
            dfs(v,w^cur);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;

    for(int i=1;i<n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        edges[u].push_back({v,w});
        edges[v].push_back({u,w});
    }

    memset(vis, false, sizeof(vis));

    dfs(1,0);

    int m;cin>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
        cout<<(dist[u]^dist[v])<<endl;
    }

    return 0;
}
