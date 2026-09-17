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

int n,m;
int dp[N];

int main()
{
    untie();

    cin>>n>>m;

    int price[m+1],imp[m+1];

    for(int i=1;i<=m;i++) cin>>price[i]>>imp[i];

    for(int i=1;i<=m;i++)
    {
        for(int j=n;j>=0;j--)
        {
            if(j-price[i]>=0) dp[j]=max(dp[j],dp[j-price[i]]+price[i]*imp[i]);
        }
    }

    cout<<dp[n]<<endl;

    return 0;
}