#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=5e5+10;
const int M=1e5+10;
const int MOD=1e9+7;

int fa[N];
vector<int> edges[M];
vector<bool> has(N,false);


void ini(int n)
{
    for(int i=0;i<=n;i++)
    {
        fa[i]=i;
    }
}

void solve()
{
    int n,m; cin>>n>>m;
    ini(n);

    for(int i=1;i<=m;i++)
    {
        int x,y; cin>>x>>y;
        edges[y].push_back(x);
    }

    for(int i=n;i>=1;i--)
    {
        if(has[i]) continue;

        queue<int> q;
        q.push(i);
        has[i]=true;

        while(!q.empty())
        {
            auto first=q.front(); q.pop();
            for(auto& v : edges[first])
            {
                if(has[v]) continue;

                fa[v]=i;
                has[v]=true;
                q.push(v);
            }
        }
    }

    for(int i=1;i<=n;i++) cout<<fa[i]<<" ";
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