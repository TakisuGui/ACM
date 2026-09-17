#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=2e5+10;

ll dis[N];
vector<pair<int,int>> edges[N];
int heap[N],pos[N],sz;   //heap记录节点名,pos记录该节点在heap中位置

void heap_swap(int i,int j)
{
    swap(pos[heap[i]],pos[heap[j]]);
    swap(heap[i],heap[j]);
}

void up_(int i)
{
    while(i>1&&dis[heap[i]]<dis[heap[i/2]])
    {
        heap_swap(i,i/2);
        i/=2;
    }
}

void down_(int i)
{
    int t=i;
    if(i*2<=sz&&dis[heap[i*2]]<dis[heap[t]]) t=i*2;
    if(i*2+1<=sz&&dis[heap[i*2+1]]<dis[heap[t]]) t=i*2+1;

    if(t!=i)
    {
        heap_swap(i,t);
        down_(t);
    }
}

void push_(int u,ll d)
{
    dis[u]=d;
    if(pos[u]==-1)
    {
        heap[++sz]=u;
        pos[u]=sz;
        up_(sz);
    }
    else if(pos[u]>0)
    {
        up_(pos[u]);
    }
}

int pop_top()
{
    int res=heap[1];
    pos[res]=-2;
    heap[1]=heap[sz]; sz--;

    if(sz>0)
    {
        pos[heap[1]]=1;
        down_(1);
    }

    return res;
}


void solve()
{
    int n,m,s; cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
    {
        dis[i]=1e9+10;
        pos[i]=-1;
    }

    for(int i=1;i<=m;i++)
    {
        int u,v,w; cin>>u>>v>>w;
        edges[u].push_back({v,w});
    }

    push_(s,0);

    while(sz)
    {
        int u=pop_top();

        for(auto have:edges[u])
        {
            int v=have.first,w=have.second;

            if(pos[v]==-2) continue;

            if(dis[v]>dis[u]+w)
            {
                push_(v,dis[u]+w);
            }
        }
    }

    for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}