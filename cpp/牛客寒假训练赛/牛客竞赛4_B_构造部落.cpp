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

int n,q;
ll s;

int main()
{
    untie();

    cin>>n>>q>>s;

    ll year[n+1]; year[0]=s;

    for(int i=1;i<=n;i++)
    {
        ll x;cin>>x;
        year[i]=x+year[i-1];
    }


    for(int i=1;i<=q;i++)
    {
        int dex,pass; cin>>dex>>pass;
        cout<<year[dex-1]+pass-1<<endl;
    }

    return 0;
}