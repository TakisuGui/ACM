#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=2e5;
const int MOD=1e9+7;


ll qpow(int a,int b,int c=MOD)
{
    ll ans=1;
    a%=c;
    while(b)
    {
        if(b&1) ans=(ans*a)%c;
        a=a*a%c;
        b>>=1;
    }
    return ans;
}


void solve()
{
    int n; cin>>n;
    int ans=0;
    ans=(ans+qpow(4,n))%MOD;
    int m=n/2;

    if(n%2==0) ans=(ans+(qpow(2,m)-1+MOD)*qpow(2,m)%MOD)%MOD;
    else ans=(ans+2*(qpow(2,m)-1+MOD)*qpow(2,m)%MOD)%MOD;

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