#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=5e5+10;
const int MOD=998244353;

map<pair<int,int>,int> w;
vector<int> edges[N];
vector<int> d(N,0);
vector<int> last(N,-1);
int start,max_d1=-1;

vector<int> dis(N,0); 
vector<int> ans(N,0); 

void dfs(int u,int f)
{
    last[u]=f;
    for(auto& v : edges[u])
    {
        if(v==f) continue;
        d[v]=d[u]+1;
        dfs(v,u);
    }
}

void dp(int u,int f)
{
    for(auto& v : edges[u])
    {
        if(v==f) continue;
        dp(v,u);
        ans[u]=max(ans[u],dis[u]+dis[v]+w[{u,v}]);
        dis[u]=max(dis[u],dis[v]+w[{u,v}]);
    }
}

void solve()
{
    int n,k; cin>>n>>k;
    for(int i=1;i<n;i++)
    {
        int u,v; cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
        w[{u,v}]=1; w[{v,u}]=1;
    }
    dfs(1,0);

    for(int i=1;i<=n;i++)
    {
        if(d[i]>max_d1)
        {
            start=i;
            max_d1=d[i];
        }
    }
    for(int i=1;i<=n;i++) d[i]=0;
    int end_; max_d1=-1;
    dfs(start,0);

    for(int i=1;i<=n;i++)
    {
        if(d[i]>max_d1)
        {
            end_=i;
            max_d1=d[i];
        }
    }

    if(k==1)
    {
        cout<<2*(n-1)-max_d1+1<<endl;
        return;
    }

    for(int i=end_;i!=start;i=last[i])
    {
        w[{i,last[i]}]=-1,w[{last[i],i}]=-1;
    }
    dp(1,0);
    int max_d2=-1;
    for(auto& x : ans) max_d2=max(max_d2,x);

    cout<<2*(n-1)-max_d1-max_d2+2<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}