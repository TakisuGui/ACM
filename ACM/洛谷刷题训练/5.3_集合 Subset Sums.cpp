#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

int main()
{
    cin>>n;

    int total=(1+n)*n/2;
    if(total%2==1)
    {
        cout<<0<<endl;
        return 0;
    }

    int taget=total/2;

    ll dp[40][800]={0};
    dp[0][0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=taget;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j-i>=0) dp[i][j]+=dp[i-1][j-i];
        }
    }

    cout<<dp[n][taget]/2<<endl;;

    return 0;
}