#include<bits/stdc++.h>
using namespace std;

int N,M;

int main()
{
    cin>>N>>M;
    int a[N+3];
    int dp[N+3][M+3];

    for(int i=1;i<=N;i++) cin>>a[i];

    for(int j=0;j<=M;j++) dp[0][j]=0;
    for(int i=0;i<=N;i++) dp[i][0]=1;

    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<=M;j++)
        {
            if(a[i]<=j) dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i]];
            else dp[i][j]=dp[i-1][j];
        }
    }

    cout<<dp[N][M]<<endl;

    return 0;
}