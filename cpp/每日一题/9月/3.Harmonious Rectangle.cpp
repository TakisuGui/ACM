#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e6+10;
const int MOD=1e9+7;

ll qpow(ll a,ll b,ll c=MOD)
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

ll c[8][8];

void init_table() 
{
    c[2][2] = 66;
    c[2][3] = 390;
    c[2][4] = 1800;
    c[2][5] = 6120;
    c[2][6] = 13680;
    c[2][7] = 15120;

    c[3][3] = 3198;
    c[3][4] = 13176;
    c[3][5] = 27000;
    c[3][6] = 13680;
    c[3][7] = 15120;

    c[4][4] = 24336;
    c[4][5] = 4320;
    c[5][5] = 4320;
}

void solve()
{
    int n,m; cin>>n>>m;
    if(n>m) swap(n,m);

    if(n==1)
    {
        cout<<0<<endl;
        return;
    }

    if(n>8||m>=8)
    {
        cout<<qpow(3,n*m)<<endl;
        return;
    }

    ll total=qpow(3,n*m);
    ll invaild=c[n][m];
    ll ans=(total-invaild+MOD)%MOD;
    cout<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    init_table();
    ll t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}