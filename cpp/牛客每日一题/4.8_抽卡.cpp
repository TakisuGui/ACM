#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int MOD=1e9+7;
const int N=1e5+10;

ll a[N];
ll b[N];
ll domin=1;
ll mole=1;

ll qpow(ll a,ll b,ll c)
{
    ll ans=1;
    a=a%c;
    while(b>0)
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
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        domin*=a[i];
        domin%=MOD;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        b[i]=a[i]-b[i];
        mole*=b[i];
        mole%=MOD;
    }

    mole=domin%MOD-mole%MOD;
    ll ans=mole*qpow(domin,MOD-2,MOD)%MOD;

    cout<<ans<<endl;
}


int main()
{
    solve();

    return 0;
}
