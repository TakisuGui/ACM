#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll INF = 2e18;

short dp[505][505];
int a[505];

void solve()
{
    int n; cin>>n;
    bool possible_S[2001]; memset(possible_S,0,sizeof(possible_S));

    for (int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            possible_S[a[i]+a[j]]=true;
    
    short max_ans=1;

    for(int s=2;s<=2000;s++)
    {
        if(!possible_S[s]) continue;

        memset(dp,0,sizeof dp);

        for(int len=1;len<=n;len++)
        {
            for(int i=1;i<=n-len+1;i++)//起点
            {
                int j=i+len-1; //终点

                if(len==1)
                {
                    dp[i][j]=(a[i]*2==s ? 1:0);
                }
                else
                {
                    if(a[i]+a[j]==s) dp[i][j]=dp[i+1][j-1]+2;
                    else
                    {
                        dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                    }
                }
            }
        }
        max_ans=max(max_ans,(short)dp[1][n]);
    }

    cout<<max_ans<<endl;
}



int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}