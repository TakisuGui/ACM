#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;

int dp[N],a[N];
int n;

int main()
{
    cin>>n;

    for(int i=1;i<=n;i++) cin>>a[i];
    dp[1]=a[1];
    int ans=dp[1];

    for(int i=1;i<=n;i++)
    {
        if(i==1) dp[1]=a[1];
        else dp[i]=max(a[i],dp[i-1]+a[i]);

        ans=max(ans,dp[i]);
    }

    cout<<ans<<endl;

    return 0;
}