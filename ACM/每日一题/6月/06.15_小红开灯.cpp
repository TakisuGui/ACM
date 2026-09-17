#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e3+10;
const int MOD=1e9+7;

ll qpow(int a,int b)
{
    ll ans=1;
    a%=MOD;
    while(b>0)
    {
        if(b&1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}

void solve()
{
    int n,k; cin>>n>>k;
    if(k==n) { cout<<2<<endl; return;}

    if(k%2==1) cout<<qpow(2,n)%MOD<<endl;
    else cout<<qpow(2,n-1)%MOD<<endl;
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