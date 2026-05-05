#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e6+10;
const ll MOD=998244353;

int t;
ll f[N+10];
ll inv_f[N+10];

ll qpow(ll a,ll b)
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

    inv_f[N-1]=qpow(f[N-1],MOD-2)%MOD;
    for(int i=N-2;i>=0;i--)
    {
        inv_f[i]=inv_f[i+1]*(i+1)%MOD;
    }
}

ll C(int n,int k)
{
    if(k<0||k>n||k<0) return 0;

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
        int n,x,k; cin>>n>>x>>k;

        if (k==0)
        {
            cout<<(x==n?1:0)<<endl;
            continue;
        }

        int group=k+1;
        ll ans=0;

        if(group%2==0)
        {
            int a=group/2;
            ans=2ll*C(x-1,a-1)%MOD*C(n-x-1,a-1)%MOD;
        }
        else
        {
            int a1=(group+1)/2,b1=(group-1)/2;
            if(b1>=1&&a1>=1&&x>=a1&&n-x>=b1) ans=(ans+(C(x-1,a1-1)%MOD)*(C(n-x-1,b1-1)%MOD))%MOD;
            
            int a2=(group-1)/2,b2=(group+1)/2;
            if(a2>=1&&b2>=1&&x>=a2&&n-x>=b2) ans=(ans+(C(x-1,a2-1)%MOD)*(C(n-x-1,b2-1)%MOD))%MOD;
        }

        cout<<ans%MOD<<endl;
    }

    return 0;
}