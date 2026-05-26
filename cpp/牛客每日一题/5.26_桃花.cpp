#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e6+10;

vector<int> edges[N];
int ans=0;

int dfs(int u,int fa)
{
    int max1=0;
    int max2=0;

    for(auto v : edges[u])
    {
        if(v==fa) continue;
        int depth=dfs(v,u)+1;

        if(depth>max1)
        {
            max2=max1;
            max1=depth;
        }
        else if(depth>max2) max2=depth;
    }
    
    ans=max(ans,max1+max2);

    return max1;
}

void solve()
{
    int n; cin>>n;

    for(int i=1;i<=n-1;i++)
    {
        int v,u; cin>>v>>u;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(1,0);

    cout<<ans+1<<endl;
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