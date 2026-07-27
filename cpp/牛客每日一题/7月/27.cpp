#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e9+7;

ll f[N+10];//阶乘
ll inv_f[N+10];//逆元
ll qpow(ll a,ll b,ll c=MOD)//(a^b) mod c
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
void init()
{
    f[0]=1;
    for(int i=1;i<N;i++)
    {
        f[i]=f[i-1]*i%MOD;
    }

    //求逆元
    inv_f[N-1]=qpow(f[N-1],MOD-2,MOD)%MOD;
    for(int i=N-2;i>=0;i--)
    {
        inv_f[i]=inv_f[i+1]*(i+1)%MOD;
    }
}


void solve()
{
    int n; cin>>n;
    vector<int> a(n+1);
    unordered_map<int,int> mp;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }

    int k=((n-1)*n*inv_f[2])%MOD;
    for(auto [key,v] : mp)
    {
        if(v>=2) k=(k-((v*(v-1)%MOD)*inv_f[2])%MOD+MOD)%MOD;
    }

    int ans=((k*f[n])%MOD*inv_f[2])%MOD;
    cout<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    int t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}