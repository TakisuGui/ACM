#include<bits/stdc++.h>
using namespace std;

const int N=5e3+10;
int n;
int a[N];
int dp[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    
    for(int i=0; i<=n;i++) dp[i]=1;
    int max_dex=dp[1];
    dp[0]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(a[i]>a[j]) dp[i]=max(dp[i],dp[j]+1);
        }

        max_dex=max(dp[i],max_dex);
    }

    cout<<max_dex<<endl;

    return 0;
}