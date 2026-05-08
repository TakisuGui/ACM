#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=305;

vector<int> edges[N];
int score[N];
int dp[N][N];
int sz[N];  //dfn的头节点子树大小
int val[N]; //dfn序下的分数
int dfn[N];
int dfncnt;
int n,m;

void ini(int n,int m)
{
    dfncnt=-1;
    for(int i=0;i<=n;i++) edges[i].clear();
    memset(dp,0,sizeof dp);
    memset(sz,0,sizeof sz);
    memset(val,0,sizeof val);
    memset(val,0,sizeof dfn);
}

void dfs(int u)
{
    int i=++dfncnt;
    dfn[u]=i;
    val[i]=score[u];
    sz[i]=1;

    for(auto v:edges[u])
    {
        dfs(v);
        sz[i]+=sz[dfn[v]];
    }
}

void solve()
{
    cin>>n>>m; m++;//虚拟节点0
    ini(n,m);

    for(int i=1;i<=n;i++)
    {
        int k,s; cin>>k>>s;
        edges[k].push_back(i);
        score[i]=s;
    }

    dfs(0);

    for(int i=n+1;i>=0;i--)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j]=max(dp[i+sz[i]][j],dp[i+1][j-1]+val[i]);
        }
    }

    cout<<dp[0][m]<<endl;
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