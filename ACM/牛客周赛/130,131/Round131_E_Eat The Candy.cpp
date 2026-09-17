#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+10;
const int MOD=998244353;
const int P=13331;

priority_queue<int,vector<int>,greater<int>> heap_small;//小跟堆
priority_queue<int,vector<int>,less<int>> heap_big;//大跟堆

ll qpow(ll a,ll b,ll c)//(a^b) mod c
{ 
    ll ans =1;
    a%=c;
    while(b)
    {
        if(b&1) ans=(ans*a) %c;
        a=a*a%c;
        b>>=1;
    }
    return ans;
}

ll gcd(ll a,ll b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}

ll floor_log2(ll x)
{
    if(x<=1) return 0;
    else return 63-__builtin_clzll(x);
}

void untie()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int count_1(ll x)
{
    return __builtin_popcountll(x);
}


int main()
{
    untie();

    int t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        vector<ll> a(n+2),temp(n+2);
        vector<ll> pre(n+2),suf(n+2);
        for(ll i=1;i<=n;i++) cin>>a[i];
        ll ans=0;

        for(ll i=1;i<=n;i++) temp[i]=a[i];

        for(ll i=2;i<=n;i++)
        {
            ll round=min(temp[i-1],temp[i]);
            pre[i]=pre[i-1]+round;;
            temp[i-1]-=round;
            temp[i]-=round;
        }

        for(ll i=1;i<=n;i++) temp[i]=a[i];

        for(ll i=n-1;i>=1;i--)
        {
            ll round=min(temp[i+1],temp[i]);
            suf[i]=suf[i+1]+round;
            temp[i+1]-=round;
            temp[i]-=round;
        }

        for(ll i=1;i<=n;i++) ans=max(ans,pre[i-1]+suf[i+1]+a[i]);

        cout<<ans<<endl;

    }

    return 0;
}