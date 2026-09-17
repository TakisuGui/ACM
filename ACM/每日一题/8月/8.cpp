#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=2e5+10;
const int MOD=1e7+7;

ll black;

void f(int i,int parent,int height,vector<vector<int>>& edges)
{
    if(height%2==0) black++;
    for(auto& v : edges[i])
    {
        if(v==parent) continue;
      
        f(v,i,height+1,edges);
    }

}

void solve()
{
    int n; cin>>n;
    vector<vector<int>> edges(n+1);
    for(int i=1;i<=n-1;i++)
    {
        int u,v; cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    black=0;
    f(1,-1,1,edges);
    
    int ans=black*(black-1)/2+black;
    cout<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}
