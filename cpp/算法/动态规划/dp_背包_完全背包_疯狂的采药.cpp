#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T,m;

int main()
{
    cin>>T>>m;
    int a[m+2],b[m+2];
    ll dp[T+3];

    for(int i=1;i<=m;i++) cin>>b[i]>>a[i];

    for(int j=0;j<=T;j++) dp[j]=0;

    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<=T;j++)
        {
            if(j-b[i]>=0)
            dp[j]=max(dp[j],a[i]+dp[j-b[i]]);

        }
    }


    cout<<dp[T]<<endl;

    return 0;
}