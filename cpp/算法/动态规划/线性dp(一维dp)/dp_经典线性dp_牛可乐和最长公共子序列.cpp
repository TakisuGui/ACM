#include<bits/stdc++.h>
using namespace std;

string s,t;


int main()
{
    cin>>s>>t;

    s=' '+s;t=' '+t;

    int n=s.size()-1;
    int m=t.size()-1;

    int dp[n+5][m+5];

    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int j=0;j<=m;j++) dp[0][j]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i]==t[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }

            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    cout<<dp[n][m]<<endl;

    return 0;
}