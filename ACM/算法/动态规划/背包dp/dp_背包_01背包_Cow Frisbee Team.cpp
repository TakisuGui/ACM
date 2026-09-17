#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD=1e8;
int n,f;

int main()
{
    cin>>n>>f;
    int a[n+2];
    int dp[n+2][1002];

    memset(dp,0,sizeof dp);
    dp[0][0]=1;

    for(int i=1;i<=n;i++)
    {
        int skill; cin>>skill;
        skill%=f;

        for(int j=0;j<f;j++) dp[i][j]=dp[i-1][j];

        for(int j=0;j<f;j++)
        {
            if(dp[i-1][j]>0)
            {
                int new_mod=(j+skill)%f;
                dp[i][new_mod]=(dp[i][new_mod]+dp[i-1][j])%MOD;
            }
        }
    }

    cout<<(dp[n][0]-1+MOD)%MOD<<endl;

    return 0;
}
