#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll INF=4e18;
#define endl "\n"

vector<ll> dis(N,INF);
vector<bool> vis(N,false);
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;

void solve()
{
    ll h,x,y,z; cin>>h>>x>>y>>z;

    if(h==1)
    {
        cout<<1<<endl;
        return;
    }

    ll mod=min({x,y,z});
    dis[1%mod]=1;
    q.push({1,1%mod});

    while(!q.empty())
    {
        auto [d,id]=q.top(); q.pop();

        if(vis[id]) continue;
        vis[id]=true;

        ll moves[3]={x,y,z};
        for(auto& k : moves)
        {
            int cur=(id+k)%mod;
            if(dis[cur]>d+k)
            {
                dis[cur]=d+k;
                q.push({dis[cur],cur});
            }
        }
    }

    ll ans=0;
    for(int r=0;r<mod;r++)
    {
        if(dis[r]<=h) ans+=(h-dis[r])/mod+1;
    }
    cout<<ans<<endl;
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