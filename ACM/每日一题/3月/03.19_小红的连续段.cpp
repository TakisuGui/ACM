#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1010;
const ll MOD=1e9+7;

ll f[N];
ll re_f[N];

ll qpow(ll a,ll b)
{
    ll ans=1;
    a%=MOD;
    while(b)
    {
        if(b&1) ans=(ans*a)%MOD;
        a=a*a%MOD;
        b=b>>1;
    }
    return ans;
}

void ini()
{
    f[0]=f[1]=1;
    for(int i=2;i<N;i++) f[i]=(f[i-1]*i%MOD);

    re_f[N-1]=qpow(f[N-1],MOD-2)%MOD;
    for(int i=N-2;i>=0;i--) re_f[i]=re_f[i+1]*(i+1)%MOD;
}

ll C(ll n,ll k)
{
    if(n<0||k>n||k<0) return 0;

    return f[n]%MOD*re_f[k]%MOD*re_f[n-k]%MOD;
}

int main()
{
    ini();
    int x,y; cin>>x>>y; int p,q;

    for(int i=1;i<=x+y;i++)
    {
        if(i%2==1)
        {
            int p1=(i+1)/2,q1=(i-1)/2; //a开头
            int p2=(i-1)/2,q2=(i+1)/2; //b开头
            ll ans=0;
            
            if(x>=p1&&y>=q1)
                ans=(ans+C(x-1,p1-1)*C(y-1,q1-1)%MOD)%MOD;
            
            if(x>=p2&&y>=q2)
                ans=(ans+C(y-1,q2-1)*C(x-1,p2-1)%MOD)%MOD;
            
            cout<<ans<<endl;
        }
        else 
        {
            p=q=i/2;
            cout<<2*C(x-1,p-1)*C(y-1,q-1)%MOD<<endl;
        }
    }

    return 0;
}