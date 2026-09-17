#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=2e5+10;

int a[N];
bool visited[N];
vector<pair<int,int>> edges[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap_small;//小跟堆

void solve()
{
    int n,m,s; cin>>n>>m>>s;
    for(int i=1;i<=n;i++) a[i]=1e9+10;

    for(int i=1;i<=m;i++)
    {
        int u,v,w; cin>>u>>v>>w;
        edges[u].push_back({v,w});
    }


    // a[1]=0; visited[1]=true;
    // for(auto pass:edges[1])
    // {
    //     heap_small.push({pass.second,pass.first}); //距离,节点
    //     a[pass.first]=pass.second;
    // }

    // while(!heap_small.empty())
    // {
    //     auto use=heap_small.top(); heap_small.pop();
    //     if(!visited[use.second])
    //     {
    //         visited[use.second]=true;
    //         for(auto have: edges[use.second])
    //         {
    //             if(!visited[have.first])
    //             {
    //                 if(a[have.first]>have.second+use.first)
    //                 {
    //                     a[have.first]=have.second+use.first;
    //                     heap_small.push({a[have.first],have.first});
    //                 }
    //             }
                
    //         }
    //     }
    // }


    a[s]=0; heap_small.push({0,s});

    while(!heap_small.empty())
    {
        auto use=heap_small.top(); heap_small.pop();
        int dis=use.first,id=use.second;

        if(visited[id]) continue;
        visited[id]=true;

        for(auto have:edges[id])
        {
            int v=have.first,w=have.second;
            if(a[v]>dis+w)
            {
                a[v]=dis+w;
                heap_small.push({a[v],v});
            }
        }
    }

    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
} 

int main()
{
    solve();

    return 0;
}