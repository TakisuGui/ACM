#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+10;
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

ll a[N],b[N];

int main()
{
    untie();

    int t;cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;

        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=m;i++) cin>>b[i];


        int j=1;
        for(int i=1;i<=n&&j<=m;i++)
        {
            if(a[i]>=b[j]) j++;   
        }

        if(j==m+1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }

    return 0;
}