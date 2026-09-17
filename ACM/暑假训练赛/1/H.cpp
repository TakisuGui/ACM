#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e7+7;
const int INF=1e18;

vector<vector<int>> edges(N);
vector<vector<int>> dp(N);

void f(int u)
{
    vector<int> childlast;

    for(auto& v : edges[u])
    {
        f(v);
        childlast.push_back(dp[v].back());
    }

    sort(childlast.begin(),childlast.end());

    dp[u].assign(childlast.size()+1,0);
    dp[u][0]=0;

    for(int i=0;i<childlast.size();i++)
    dp[u][i+1]=max(dp[u][i]+1,childlast[i]+1);
}

void solve()
{
    int n; cin>>n;
    for(int i=2;i<=n;i++)
    {
        int x; cin>>x;
        edges[x].push_back(i);
    }
    f(1);

    cout<<dp[1].back()<<endl;
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