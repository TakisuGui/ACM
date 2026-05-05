#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=2e5+10;

void solve()
{
    ll n,m;
    cin>>n>>m;

    if(!(2*m<=n && n<=1+(m+1)*m/2))
    {
        cout<<"NO"<<endl;
        return;
    }

    vector<ll> cnt(n+1);
    cnt[m]=1;

    ll rest=n-2;
    for(int d=m-1;d>=1;d--)
    {
        ll x=min(cnt[d+1]+1,rest-(d-1)*2ll);
        cnt[d]=x;
        rest-=x;
    }

    vector<pair<ll,ll>> edges;

    ll id=2;
    vector<int> fa={1};

    for(ll d=1;d<=m;d++)
    {
        vector<int> cur(cnt[d]);
        for(int i=0;i<cnt[d];i++) cur[i]=id++;

        int p=(int)fa.size();

        for(int i=0;i<p;i++) edges.push_back({fa[i],cur[i]});

        for(int i=p;i<cnt[d];i++) edges.push_back({fa[0],cur[i]});

        if(d<m) fa.assign(cur.begin(),cur.end()-1);
    }

    cout << "YES" << endl;
    for (auto [u, v] : edges) cout << u << " " << v << endl;
}


int main()
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