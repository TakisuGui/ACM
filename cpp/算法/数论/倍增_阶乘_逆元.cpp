#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e6+10;
const ll MOD=1e9+7;

int t;
int b,g,x,y;
ll f[N+10];//阶乘
ll inv_f[N+10];//逆元

ll qpow(ll a,ll b)//快速幂
{
    ll res=1;
    while(b)
    {
        if(b&1) res=res*a%MOD;
        a=a*a%MOD;
        b=b>>1;
    }

    return res;
}

void init()
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();

    cin>>t;
    while(t--)
    {
        cin>>b>>g>>x>>y;

       if (x+y>g)
        {
            cout <<"0\n";
        }
       else
        {
            ll ans = C(b + g, g) - C(b + x + y - 1, x + y - 1);
            ans = (ans % MOD + MOD) % MOD;
            cout <<ans<<endl;
        }
    }

    return 0;
}