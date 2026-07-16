#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10+10;

int a[N],b[N];
vector<vector<int>> mp(N);

void solve()
{
    int n,k,m; cin>>n>>k>>m;
    for(int i=1;i<=n;i++)
    {
        int c,v; cin>>c>>v;
        mp[c].push_back(v);
    }

    vector<ll> first; 
    vector<ll> rest;

    for(int color=1;color<=n;color++)
    {
        if(mp[color].empty()) continue;
        sort(mp[color].rbegin(),mp[color].rend());

        first.push_back(mp[color][0]);
        for (int i=1; i<mp[color].size();i++) rest.push_back(mp[color][i]);
    }

    sort(first.rbegin(),first.rend());
    sort(rest.rbegin(),rest.rend());

    int first_cnt=first.size();
    int rest_cnt=rest.size();
    
    vector<ll>first_sum(first_cnt+1,0);
    for (int i=0; i<first_cnt;i++) first_sum[i+1]=first_sum[i]+first[i];
    vector<ll> rest_sum(rest_cnt+1,0);
    for(int i=0; i<rest_cnt;i++)  rest_sum[i+1]=rest_sum[i]+rest[i];

    ll ans=0;
    for (int x=m; x<=min(k,first_cnt);x++) 
    {
        if (k-x<=rest_cnt)
        {
            ll total=first_sum[x]+rest_sum[k-x];
            ans=max(ans,total);
        }
    }

    cout<<ans<<endl;
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