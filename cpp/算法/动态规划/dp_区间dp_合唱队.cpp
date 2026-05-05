#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e3+10;
const int MOD=19650827;

int n;
int nums[N];
int dp[N][N][2];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>nums[i];

    for(int i=1;i<=n;i++) dp[i][i][0]=1,dp[i][i][1]=1;

    for(int i=1;i<n;i++)
    {
        if(nums[i]<nums[i+1]) dp[i][i+1][0]=1,dp[i][i+1][1]=1;
        else                  dp[i][i+1][0]=0,dp[i][i+1][1]=0;
    }

    for(int len=3;len<=n;len++)
    {
        for(int l=1;l+len-1<=n;l++)
        {
            int r=l+len-1;

            if(nums[l]<nums[l+1]) dp[l][r][0]=(dp[l][r][0]+dp[l+1][r][0])%MOD;
            if(nums[l]<nums[r])   dp[l][r][0]=(dp[l][r][0]+dp[l+1][r][1])%MOD;
            if(nums[r]>nums[r-1]) dp[l][r][1]=(dp[l][r][1]+dp[l][r-1][1])%MOD;
            if(nums[r]>nums[l])   dp[l][r][1]=(dp[l][r][1]+dp[l][r-1][0])%MOD;
        }
    }

    int ans=(dp[1][n][0]+dp[1][n][1])%MOD;

    cout<<ans<<endl;
}

signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}