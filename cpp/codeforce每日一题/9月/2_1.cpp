#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e18;
const int MOD=1e7+7;

ll exgcd(ll a,ll b,ll& x,ll& y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    ll x1,y1;
    ll d=exgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}


void solve()
{
    ll a,b,c; cin>>a>>b>>c;
    ll x,y;
    ll g=exgcd(a,b,x,y);

    ll tar=-c;
    if(tar%g!=0) cout<<-1<<endl;
    else
    {
        ll k=tar/g;
        ll ans_x=x*k,ans_y=y*k;
        cout<<ans_x<<" "<<ans_y<<endl;
    }
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