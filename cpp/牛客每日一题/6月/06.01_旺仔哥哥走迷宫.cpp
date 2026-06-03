#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{
    int n,m; cin>>n>>m;
    vector<int> pass(n+1);
    for(int i=1;i<=n;i++) {int x; cin>>x; pass[i]=(x==0 ? 1 : 0);}
    vector<vector<int>> edges(n+1);

    if(!pass[1]||n==1) {cout<<"No"<<endl; return;}

    for(int i=1;i<=m;i++)
    {
        int u,v; cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    queue<int> q;
    vector<bool> vis(n+1,0);
    q.push(1);
    vis[1]=true;
    bool can=false;

    while(!q.empty())
    {
        auto cur=q.front(); q.pop();

        for(auto next : edges[cur])
        {
            if(vis[next]||!pass[next]) continue;
            if(next==n)
            {
                can=true;
                break;
            }
            vis[next]=true;
            q.push(next);
        }
    }

    cout<<(can ? "Yes" : "No")<<endl;
}


signed main()
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