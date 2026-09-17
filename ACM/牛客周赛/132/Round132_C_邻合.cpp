#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+10;
const int MOD=998244353;
const int P=13331;
const int INF=0x3f3f3f3f;

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

int gcd(int a,int b)
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

int a[N];
int dp[N][2];

// dp
// int main()
// {
//     untie();

//     int t;cin>>t;
//     while(t--)
//     {
//         int n; cin>>n;
//         for(int i=1;i<=n;i++) cin>>a[i];
//         for(int i=1;i<=n;i++) dp[i][0]=dp[i][1]=n+5;
//         dp[1][0]=0;
//         dp[1][1]=1;

//         for(int i=2;i<=n;i++)
//         {
//             if(gcd(a[i-1],a[i])>1) dp[i][0]=min(dp[i][0],dp[i-1][0]);
//             dp[i][0]=min(dp[i][0],dp[i-1][1]);

//             dp[i][1]=min(dp[i-1][0],dp[i-1][1])+1;
//         }

//         cout<<min(dp[n][0],dp[n][1])<<endl;

//     }

//     return 0;
// }

int main()
{
    untie();

    int t;cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<int> a(n+2);
        for(int i=1;i<=n;i++) cin>>a[i];
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            if(gcd(a[i],a[i-1])==1)
            {
                a[i]=0;
                ans++;
            }
        }
        cout<<ans<<endl;      
    }
    return 0;
}