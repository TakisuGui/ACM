#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int N=1e6+10;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,t,x; cin>>n>>m>>t>>x;

    vector<int> edges[N];
    for(int i=0;i<m;i++)
    {
        int u,v; cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<int> dis(n+1,-1);
    dis[x]=0;
    queue<int> q;
    q.push(x);

    while(!q.empty())
    {
        int u=q.front(); q.pop();
        for(auto v:edges[u])
        {
            if(dis[v]==-1)
            {
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }

    vector<int> cnt(5001,0);
    for(int i=1;i<=n;i++)
    {
        if(dis[i]==-1) continue;
        cnt[dis[i]]++;
    }

    vector<int> dp(5001,0);
    dp[0]=1;
    for(int d=1;d<=5000;d++)
    {
        if(cnt[d]==0) continue;

        for(int j=d;j>=1;j--) dp[j]=(dp[j]+dp[j-1]*(1ll)*cnt[d])%MOD;
    }

    while(t--)
    {
        int k; cin>>k;
        cout<<dp[k]<<endl;
    }

    return 0;
}