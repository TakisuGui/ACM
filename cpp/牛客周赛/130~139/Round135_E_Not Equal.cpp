#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;

ll a[N],b[N],c[N];

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        for(int i=1;i<=n;i++) cin>>c[i];

        vector<vector<ll>> dp(n+1,vector<ll>(5,1e18));
        //0->-2,1->-1,2->+0,3->+1,4->+2
        dp[1][2]=0;
        dp[1][3]=b[1];
        dp[1][4]=b[1]+b[1];
        if(a[1]-1>0) dp[1][1]=c[1];
        if(a[1]-2>0) dp[1][0]=c[1]+c[1];

        for(int i=2;i<=n;i++)
        {
            for(int j=-2;j<=2;j++)//第i-1个数的增加量
            {
                for(int k=-2;k<=2;k++)//第i个数的增加量
                {
                    if(a[i-1]+j==a[i]+k) continue;
                    if(a[i]+k<=0) continue;

                    if(k<0) dp[i][k+2]=min(dp[i][k+2],dp[i-1][j+2]+abs(k)*c[i]);
                    else    dp[i][k+2]=min(dp[i][k+2],dp[i-1][j+2]+abs(k)*b[i]);
                }
            }
        }

        ll ans=1e18;
        for(int i=-2;i<=2;i++) ans=min(ans,dp[n][i+2]);

        cout<<ans<<endl;
    }

    return 0;
}