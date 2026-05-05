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

int n;
int a[2050],b[2050];
bool dp[2050][2048];

int main()
{
    untie();

    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    dp[0][0]=true;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<2048;j++)
        {
            if(!dp[i-1][j]) continue;

            int next1=max(0,j-a[i]);
            dp[i][next1]=true;

            int next2=j^b[i];
            dp[i][next2]=true;
        }
    }

    for(int i=2047;i>=0;i--)
    {
        if(dp[n][i])
        {
            cout<<i<<endl;
            return 0;
        }
    }


    return 0;
}