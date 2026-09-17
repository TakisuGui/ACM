#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;

vector<int> edges[N];
bool visited[N];

int main()
{
    int n,m; cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int u,v; cin>>u>>v;
        edges[u].push_back(v);
    }

    queue<int> q; int ans=1;
    q.push(1);
    visited[1]=true;

    while(!q.empty())
    {
        auto front=q.front(); q.pop();
        for(auto v:edges[front])
        {
            if(!visited[v])
            {
                visited[v]=true;
                ans++;
                q.push(v);
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}