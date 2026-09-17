#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

vector<int> edges[N];
vector<pair<int/*该节点在父节点的高度*/,int/*子节点*/>> child_info[N]; //存储它的所有子节点以及每个子节点对应的管道连接高度
int val[N];                          
int high[N];
int node_water[N]; //u为根的子树,从u没有满到u完全注满所需的总水量
int total_water[N]; //节点u被注水前系统的总注水量
int ans[N];

void dfs(int u) //预处理每个节点自身接满要多少水
{
    for(auto v :edges[u]) child_info[u].push_back({high[v],v});

    sort(child_info[u].begin(),child_info[u].end()); //由下到上排列子节点

    for(auto v :child_info[u])
    {
        int child=v.second;
        dfs(child);
    }

    node_water[u]=val[u];
    for(auto v :child_info[u])
    {
        int child=v.second;
        node_water[u]+=node_water[child];
    }
}

void calcu(int u,int cur_water)
{
    total_water[u]=cur_water; //在无关u的时候已经用水(u的所有祖先节点中已经注入的水,u的祖先节点的其他已处理完的子树中注入的水)
    int last_high=0; //u节点所处理的上一个子节点高度,一开始没有处理过,初始化为0
    int accumulated_base=cur_water;

    for(auto [child_high,child] : child_info[u])
    {
        accumulated_base+=(child_high-last_high);
        last_high=child_high;

        calcu(child,accumulated_base);

        accumulated_base+=node_water[child]; //child的祖先节点(u)的其他已处理完的子树中注入的水
    }

    ans[u]=accumulated_base+(val[u]-last_high);
}

void solve()
{   
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>val[i];

    for(int i=2;i<=n;i++)
    {
        int x; cin>>x;
        edges[x].push_back(i);
    }

    for(int i=2;i<=n;i++) cin>>high[i];

    dfs(1);
    total_water[1]=0;
    calcu(1,0);

    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
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