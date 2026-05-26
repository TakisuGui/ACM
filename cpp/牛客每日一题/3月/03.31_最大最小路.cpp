#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
int w[N];
vector<int> edges[N];
ll ans;
ll dp[N][4];
int n,a,b;

void dfs(int u,int fa)
{
    if(a<w[u]&&w[u]<b) dp[u][0]+=1;
    if(w[u]<=a) dp[u][1]+=1;
    if(w[u]>=b) dp[u][2]+=1;
    for(auto v:edges[u])
    {
        if(v==fa) continue;
        dfs(v,u);
        ans+=(dp[u][0]+dp[u][1]+dp[u][2])*dp[v][3];
        ans+=(dp[v][0]+dp[v][1]+dp[v][2])*dp[u][3];
        ans+=dp[v][3]*dp[u][3];
        ans+=dp[v][2]*dp[u][1];
        ans+=dp[v][1]*dp[u][2];

        if(w[u]<=a)
        {
            dp[u][1]+=dp[v][1]+dp[v][0];
            dp[u][3]+=dp[v][3]+dp[v][2];
        }
        if(w[u]>=b)
        {
            dp[u][2]+=dp[v][0]+dp[v][2];
            dp[u][3]+=dp[v][3]+dp[v][1];
        }
        if(a<w[u]&&w[u]<b)
        {
            for(int j=0;j<=3;j++) dp[u][j]+=dp[v][j];
        }
    }
}

int main()
{
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++) cin>>w[i];

    for(int i=2;i<=n;i++)
    {
        int u,v; cin>>u>>v;
        edges[v].push_back(u);
        edges[u].push_back(v);
    }

    dfs(1,0);

    cout<<ans<<endl;

    return 0;
}