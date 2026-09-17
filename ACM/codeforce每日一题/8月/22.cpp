#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=5e5+10;
const int MOD=1e9+7;

int n,k;
vector<int> a(N);
vector<vector<int>> tree(13,vector<int>(N));
vector<vector<int>> dp(N,vector<int>(13));

int lowbit(int x)
{
    return x&(-x);
}

void add(int len,int i,int v)
{
    while(i<=n)
    {
        tree[len][i]+=v;
        i+=lowbit(i);
    }
}

int sum(int len,int i)
{
    int ans=0;
    while(i>0)
    {
        ans+=tree[len][i];
        i-=lowbit(i);
    }
    return ans;
}

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++)
    {
        dp[i][1]=1;
        add(1,a[i],1);

        for(int len=2;len<=k+1;len++)
        {
            dp[i][len]+=sum(len-1,a[i]-1);
            add(len,a[i],dp[i][len]);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans+=dp[i][k+1];
    cout<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}