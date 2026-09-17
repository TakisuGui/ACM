#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+10;

int n,m;
vector<int> edges[N];
queue<int> q;
int dp[N];
int tep_in[N];
int indeg[N];
int outdeg[N];

int main()
{
    cin>>n>>m;

    while(m--)
    {
        int x,y; cin>>x>>y;
        edges[x].push_back(y);
        indeg[y]++;
        outdeg[x]++;
        tep_in[y]++;
    }

    ll ans=0;

    for(int i=1;i<=n;i++)
    {
        if(indeg[i]==0)
        {
            q.push(i);
            dp[i]=1;
        }
    }

    while(!q.empty())
    {
        auto u=q.front(); q.pop();

        for(auto v:edges[u])
        {
            tep_in[v]--;
            dp[v]+=dp[u];

            if(tep_in[v]==0) q.push(v);
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(outdeg[i]==0) ans+=dp[i];
    }

    // 减去重复计算的孤立点
    for(int i=1;i<=n;i++)
    {
        if(indeg[i]==0&&outdeg[i]==0)
        {
            ans--;
        }
    }

    cout<<ans<<endl;

    return 0;
}