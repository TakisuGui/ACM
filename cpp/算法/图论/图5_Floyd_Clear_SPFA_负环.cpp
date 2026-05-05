#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=2e3+10;
const int M=3e3+10;

bool visited[N];
vector<pair<int,int>> edges[N];
ll dis[N];
int untie[N];

void solve()
{
    int n,m; cin>>n>>m;
 
    for(int i=1;i<=n;i++)
    {
        edges[i].clear();
        visited[i]=false;
        dis[i]=1e9+10;
        untie[i]=0;
    }

    for(int i=1;i<=m;i++)
    {
        int u,v,w; cin>>u>>v>>w;

        if(w>=0)
        {
            edges[v].push_back({u,w});
            edges[u].push_back({v,w});
        }
        else edges[u].push_back({v,w});
    }

    queue<int> q;

    q.push(1); dis[1]=0; visited[1]=true; untie[1]++; bool neg=false;

    while(!q.empty())
    {
        auto top=q.front(); q.pop(); visited[top]=false;

        for(auto have:edges[top])
        {
            int id=have.first,price=have.second;

            if(dis[id]>dis[top]+price)
            {
                dis[id]=dis[top]+price;
                untie[id]++;

                if(untie[id]>n-1)
                {
                    neg=true;
                    break;
                }
                
                if(!visited[id])
                {
                    q.push(id); 
                    visited[id]=true;
                }
            }
        }
    }

    cout<<(neg ? "YES" : "NO")<<endl;
}



int main()
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