#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+10;
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
        int n,m; cin>>n>>m;
        vector<string> s(n);
        for(int i=0;i<n;i++) cin>>s[i];
        vector<int> cnt(m);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s[i][j]=='1') cnt[j]++;
            }
        }

        for(int i=0;i<n;i++)
        {
            int dp[m+1][3];
            dp[0][0]=0; dp[0][1]=INF; dp[0][2]=INF;

            for(int j=0;j<m;j++)
            {
                int c; //代价
                if(s[i][j]=='1') c=n-cnt[j]; //0的个数
                else c=cnt[j]; //1的个数

                dp[j+1][0]=dp[j][0]+c;
                dp[j+1][1]=min(dp[j][0],dp[j][1])+(n-c-1);
                dp[j+1][2]=min({dp[j][0],dp[j][1],dp[j][2]})+c; //状态0:相当于没翻; 状态1:这个位置结束翻; 状态2:继续结束状态
            }

            cout<<min({dp[m][2],dp[m][1],dp[m][0]})<<endl;

        }
    }

    return 0;
}