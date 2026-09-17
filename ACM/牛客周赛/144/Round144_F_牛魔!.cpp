#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

int n;
int a[N];
vector<int> edges[N];
int fa[N],dep[N],bel[N],ok[N]/*是否有孙节点*/;

void dfs_greedy(int u, int f) 
{
    fa[u]=f;
    if(u==1) dep[u]=0;
    else dep[u]=dep[f]+1;
    
    for(int v : edges[u]) {
        if(v==f) continue;

        bel[v] = (u==1 ? v : bel[u]);
        dfs_greedy(v, u); //先处理子树（孙子们）
    }

    //后序位置：此时u的所有子节点都已经处理完毕
    if(dep[u]>=2) 
    {
        ok[bel[u]]=1;  //标记这棵大子树够深
        if(a[u]==0) //如果孙节点是0强制翻转
        { 
            a[u]^=1;
            a[fa[u]]^=1;
            a[fa[fa[u]]]^=1;
        }
    }
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++)
    {
        int u,v; cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    if(n==1) { cout<<a[1]<<endl; return; }

    dfs_greedy(1,0);
    
    int ans=0;
    for(int i=1;i<=n;i++) ans+=a[i];

    if(a[1]==0)
    {
        for(int v : edges[1])
        {
            if(v!=0&&a[v]==0&&ok[v])
            {
                ans++;
                break;
            }
        }
    }

    cout<<ans<<endl;
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