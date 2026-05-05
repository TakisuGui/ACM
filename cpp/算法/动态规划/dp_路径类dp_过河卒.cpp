#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
int house1,house2;
int dx[8]={2,1,-1,-2,-2,-1,1,2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};

int main()
{
    cin>>n>>m>>house1>>house2;
    ll dp[n+2][m+2];
    memset(dp,0,sizeof dp);
    dp[1][1]=1;
    dp[house1+1][house2+1]=-1;

    for(int i=0;i<8;i++)
    {
        if(house1+dx[i]+1>=1&&house1+dx[i]+1<=n+1&&house2+dy[i]+1>=1&&house2+dy[i]+1<=m+1)
        {
            dp[house1+dx[i]+1][house2+dy[i]+1]=-1;
        }
    }

    if(dp[1][1]==-1)
    {
        cout<<"0"<<endl;
        return 0;
    }

    for(int i=1;i<=n+1;i++)
    {
        for(int j=1;j<=m+1;j++)
        {
            if(i==1&&j==1) continue;

            if(dp[i][j]!=-1)
            {
                if(dp[i-1][j]!=-1&&dp[i][j-1]!=-1)
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }

                else if(dp[i-1][j]==-1) dp[i][j]=dp[i][j-1];
                else dp[i][j]=dp[i-1][j];

            }

            else continue;
        }
    }

    cout<<dp[n+1][m+1]<<endl;

    return 0;
}