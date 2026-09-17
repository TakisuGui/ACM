#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e6+10;
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

ll n,m;
ll classroom[N];
ll f[N];
ll d[N],s[N],t[N];

bool check(int mid)
{
    memset(f,0,sizeof f);

    for(int i=1;i<=mid;i++)
    {
        f[s[i]]+=d[i];
        f[t[i]+1]-=d[i];
    }

    ll cur=0;
    for(int i=1;i<=n;i++)
    {
        cur+=f[i];
        if(cur>classroom[i]) return false;
    }

    return true;
}


int main()
{
    untie();

    cin>>n>>m;

    for(ll i=1;i<=n;i++) cin>>classroom[i];

    bool dis=true;
    for(ll i=1;i<=m;i++) cin>>d[i]>>s[i]>>t[i];

    int left=1,right=m,wa=0;

    while(left<=right)
    {
        int mid=(left+right)/2;
        if(check(mid)) left=mid+1;
        else
        {
            right=mid-1;
            wa=mid;
            dis=false;
        }
    }
    

    if(dis) cout<<"0"<<endl;
    else cout<<"-1"<<endl<<wa<<endl;

    return 0;
}