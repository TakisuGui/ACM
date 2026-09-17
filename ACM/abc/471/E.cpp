#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define endl "\n"

const int N=2e5+10;
const int mod=1e9+7;
const int MOD=998244353;
const int P=13331;
const int INF=0x3f3f3f3f;
const double EPS=1e-6;
ll f[N+10];//阶乘
ll inv_f[N+10];//逆元
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
priority_queue<int,vector<int>,greater<int>> heap_small;//小跟堆
priority_queue<int,vector<int>,less<int>> heap_big;//大跟堆

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
void untie()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
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
ll C(int n,int k)
{
    if(k<0||k>n) return 0;

    return f[n]%MOD*inv_f[k]%MOD*inv_f[n-k]%MOD;
}


void solve()
{
    int n,k; cin>>n>>k;
    init();

    ll S1=0,S2=0;
    for(int i=0;i<n;i++) 
    {
        ll a; cin>>a;
        a%=MOD;
        S1=(S1+a)%MOD;
        S2=(S2+a*a)%MOD;
    }
    ll ans=0;

    ll c1=C(n-1,k-1);
    ans=(ans+c1*S2)%MOD;
 
    ll c2=C(n-2,k-2);
    ll diff=(S1*S1%MOD-S2+MOD)%MOD;
    ans=(ans+c2*diff)%MOD;
    
    cout<<ans<<endl;
}

signed main()
{
    untie();

    int t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}

