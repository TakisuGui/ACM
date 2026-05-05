#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+10;
const int MOD=998244353;

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

void untie()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}


int n,w,m;
vector<int> edges[N];
int value[N],spent[N];
int comb_value[N],comb_spent[N];
int cnt=0;
bool pass[N];
int dp[N];

void dfs(int a)
{
    pass[a]=true;
    comb_value[cnt]+=value[a];
    comb_spent[cnt]+=spent[a];

    for(auto b:edges[a])
    {
        if(!pass[b]) dfs(b);
    }
}

int main()
{
    cin>>n>>m>>w;

    for(int i=1;i<=n;i++) cin>>spent[i]>>value[i];
    
    for(int i=1;i<=m;i++)
    {
        int a,b; cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for(int i=1;i<=n;i++)
    {
        if(!pass[i])
        {
            cnt++;
            dfs(i);
        }
    }

    for(int i=1;i<=cnt;i++)
    {
        for(int j=w;j>=0;j--)
        {
            if(j-comb_spent[i]>=0) dp[j]=max(dp[j],dp[j-comb_spent[i]]+comb_value[i]);
        }
    }

    cout<<dp[w]<<endl;

    return 0;
}