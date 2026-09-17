#include<bits/stdc++.h>
using namespace std;

int T,M;

int main()
{
    cin>>T>>M;
    int a[M+3],b[M+3];
    int dp[M+3][T+3];

    for(int i=1;i<=M;i++)
    {
        cin>>b[i]>>a[i];
    }

    for(int i=0;i<=M;i++) dp[i][0]=0;
    for(int j=0;j<=T;j++) dp[0][j]=0;

    for(int i=1;i<=M;i++)
    {
        for(int j=1;j<=T;j++)
        {
            if(b[i]<=j) dp[i][j]=max(dp[i-1][j],a[i]+dp[i-1][j-b[i]]);
            else dp[i][j]=dp[i-1][j];
        }
    }

    cout<<dp[M][T]<<endl;

    return 0;
}