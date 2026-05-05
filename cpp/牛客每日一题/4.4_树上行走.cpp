#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;

vector<int> edges0[N];
vector<int> edges1[N];
int a[N];
bool vis[N];


vector<int> get_component(int u, int group)
{
    queue<int> q;
    vector<int> nodes;//记录走过的节点
    q.push(u);
    vis[u]=true;

    while(!q.empty())
    {
        auto top=q.front(); q.pop(); nodes.push_back(top);

        if(group==0) for(auto v:edges0[top])
        {
            if(vis[v]) continue;
            q.push(v);
            vis[v]=true;
        }
        else for(auto v:edges1[top])
        {
            if(vis[v]) continue;
            q.push(v);
            vis[v]=true;
        }
    }

    return nodes;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n-1;i++)
    {
        int v,u; cin>>u>>v;
        if(a[v]==0&&a[u]==0)
        {
            edges0[u].push_back(v);
            edges0[v].push_back(u);
        }
        else if(a[v]==1&&a[u]==1)
        {
            edges1[u].push_back(v);
            edges1[v].push_back(u);
        }
    }

    int max_size=0;
    vector<vector<int>> all_comps;

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vector<int> comp=get_component(i,a[i]);
            int sz=comp.size();
            if(sz>max_size) max_size=sz;
            all_comps.push_back(comp);
        }
    }

    vector<int> result;
    for(auto &comp:all_comps)
    {
        if(comp.size()==max_size)
        {
            for(auto node:comp) result.push_back(node);
        }
    }

    sort(result.begin(),result.end());

    cout<<result.size()<<"\n";
    for(int i=0;i<result.size();i++) cout<<result[i]<<(i==result.size()-1?"":" ");
    cout<<endl;

    return 0;
}