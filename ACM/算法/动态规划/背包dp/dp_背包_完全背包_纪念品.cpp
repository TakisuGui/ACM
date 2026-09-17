#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t,n,m;
    cin>>t>>n>>m;

    int price[t+1][n+1];
    for(int day=1;day<=t;day++)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>price[day][i];
        }
    }

    for(int today=1;today<t;today++)
    {
        int tomorrow=today+1;
        int dp[n+2][m+2];
        memset(dp,0,sizeof dp);

        for(int i=1;i<=n;i++)
        {
            int cost=price[today][i];
            int sell=price[tomorrow][i];
            int profit=sell-cost;

            for(int j=0;j<=m;j++)
            {
                dp[i][j]=dp[i-1][j];

                if(j>=cost&&profit>0)
                {
                    dp[i][j]=max(dp[i][j],dp[i][j-cost]+profit);
                }
            }
        }
        m=m+dp[n][m];
    }

    cout<<m<<endl;

    return 0;
}