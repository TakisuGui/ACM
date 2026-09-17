#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e18;
const int MOD=1e7+7;

ll qpow(ll a,ll b)//(a^b) 
{ 
    ll ans=1;
    while(b)
    {
        if(ans>N/a) return N+1;
        if(b&1) ans=(ans*a);

        b>>=1;
        if(a>N/a&&b) return N+1;
        a=a*a;
    }
    return ans;
}

ll get_n(int p,int q)
{
    int n=0;
    if(qpow(p,q)>N) return n;

    ll an=qpow(p,q);
    n++;

    int cur=get_n(q,an);
    return n+cur;
}


void solve()
{
    int p,q; cin>>p>>q;
    cout<<get_n(p,q)+2<<endl;
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