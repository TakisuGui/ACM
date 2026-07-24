#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e6+10;
const int MOD=998244353;

ll qpow(ll a,ll b)//(a^b) mod c
{ 
    ll ans=1;
    a%=MOD;
    while(b)
    {
        if(b&1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans%MOD;
}

ll f[N+10];//阶乘
ll inv_f[N+10];//逆元

long long modInverse(long long n) 
{
    return qpow(n,MOD-2);
}

void ini()
{
    f[0]=1;
    for(int i=1;i<N;i++)
    {
        f[i]=f[i-1]*i%MOD;
    }

    //求逆元
    inv_f[N-1]=qpow(f[N-1],MOD-2)%MOD;
    for(int i=N-2;i>=0;i--)
    {
        inv_f[i]=inv_f[i+1]*(i+1)%MOD;
    }
}

ll C(int n,int k)
{
    if(k<0||k>n) return 0;
    return f[n]%MOD*inv_f[k]%MOD*inv_f[n-k]%MOD;
}


void solve()
{
    ll n,m,c,a,b; cin>>n>>m>>c>>a>>b;

    if(m<n||(m-n)%c!=0)
    {
        cout<<0<<endl;
        return;
    }

    ll k=(m-n)/c;
    if(k<0||k>m)
    {
        cout<<0<<endl;
        return;
    }

    ll invb=modInverse(b);
    ll p_win=(a*invb)%MOD;
    ll p_lose=((b-a+MOD)%MOD*invb)%MOD;

    ll ans=(n%MOD)*modInverse(m)%MOD;
    ans=(ans*C(m,k))%MOD;
    ans=(ans*qpow(p_win,k))%MOD;
    ans=(ans*qpow(p_lose,m-k))%MOD;

    cout<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ini();
    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}
