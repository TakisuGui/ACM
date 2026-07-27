#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e9+7;

vector<int> dp(N);
vector<int> cnt(N);
vector<int> pow2(N);

void ini()
{
    pow2[0]=1;
    for(int i=1;i<N;i++)
    {
        pow2[i]=(pow2[i-1]*2)%MOD;
    }
}


void solve()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        cnt[x]++;
    }

    for(int i=100000;i>=1;i--)
    {
        int counts=0;
        for(int j=i;j<=100000;j+=i)
        {
            counts+=cnt[j];
        }
        dp[i]=(pow2[counts]-1+MOD)%MOD;

        for(int j=2*i;j<=100000;j+=i) dp[i]=(dp[i]-dp[j]+MOD)%MOD;
    }

    cout<<dp[1]<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ini();

    int t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}