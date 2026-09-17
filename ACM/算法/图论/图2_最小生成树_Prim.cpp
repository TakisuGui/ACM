#include<bits/stdc++.h>
using namespace std;
using Edge=pair<int,int>;
typedef long long ll;
const int N=5e3+10;
const int M=2e5+10;

vector<pair<int,int>> edges[M];
priority_queue<Edge,vector<Edge>,greater<Edge>> heap_small;
bool visited[N];

void solve()
{
    int n,m; cin>>n>>m; ll ans=0; int cnt=0;

    for(int i=1;i<=m;i++)
    {
        int x,y,z; cin>>x>>y>>z;

        edges[x].push_back({y,z});
        edges[y].push_back({x,z});
    }

    for(auto [v,w]:edges[1]) heap_small.push({w,v});
    cnt++;
    visited[1]=true;

    while(!heap_small.empty())
    {
        auto [cost,next]=heap_small.top(); heap_small.pop();

        if(!visited[next])
        {
            cnt++;
            visited[next]=true;
            ans+=cost;
        }
        for(auto [v,w]:edges[next])
        {
            if(!visited[v]) heap_small.push({w,v});
        }
    }

    if(cnt==n) cout<<ans<<endl;
    else cout<<"orz"<<endl;

}


int main()
{
    solve();

    return 0;
}