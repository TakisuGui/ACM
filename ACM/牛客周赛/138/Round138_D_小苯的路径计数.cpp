#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;

vector<int> color(N);
vector<int> dp(N,0);
vector<int> edges[N];
ll ans;

void dfs(int u,int fa)
{
    if(fa!=0&&color[u]==color[fa])
    {
        dp[u]=dp[fa]+1;
    }
    else dp[u]=0;

    ans+=dp[u];

    for(auto v:edges[u])
    {
        if(v==fa) continue;
        dfs(v,u);
    }
}


void solve()
{
    int n; cin>>n;

    ans = 0;
    for(int i=1;i<=n;i++)
    {
        edges[i].clear();
        dp[i]=0;
    }


    for(int i=1;i<=n;i++) cin>>color[i];
    for(int i=1;i<=n-1;i++)
    {
        int u,v; cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(1,0);

    cout<<ans<<endl;
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