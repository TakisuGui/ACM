#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    typedef long long ll;
    const int MOD=1e9+7;
    const int N=110;
    vector<ll> f=vector<long long>(N);
    vector<ll> inv_f=vector<long long>(N);

    ll qpow(ll a,ll b)
    { 
        ll ans=1;
        a%=MOD;
        while(b)
        {
            if(b&1) ans=(ans*a)%MOD;
            a=a*a%MOD;
            b>>=1;
        }
        return ans;
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

    ll fn(int n,int l,int k)
    {
        return ((f[n]%MOD*qpow(n-k,l-k))%MOD*inv_f[n-k])%MOD;
    }

    int numMusicPlaylists(int n,int l,int k)
    {
        init();
        ll ans=0;
        for(int i=0;i<n-k;i++)
        {
            if(i%2==0) ans=(ans+C(n,i)%MOD*fn(n-i,l,k)%MOD)%MOD;
            else ans=(((ans-C(n,i)%MOD*fn(n-i,l,k)%MOD)%MOD+MOD)%MOD)%MOD;
        }
        return ans;
    }
};