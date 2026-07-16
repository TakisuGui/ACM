#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;
const int MOD=998244353;

int cnt[14];
int dp[14][3][3];

void solve()
{   
    int n,a,b; cin>>n>>a>>b;
    for(int i=1;i<=n;i++) {int x; cin>>x; cnt[x]++;}

    memset(dp,-0x3f,sizeof dp);

    dp[0][0][0]=0;
    for(int i=1;i<=13;i++)
    {
        for(int pre_pre=0;pre_pre<3;pre_pre++) // i-2 为起点的顺子
        {
            for(int pre=0;pre<3;pre++) // i-1 为起点的顺子
            {
                for(int cur=0;cur<3;cur++) // i 为起点的顺子
                {
                    if(i>11 &&cur>0) continue;
                    int used=pre_pre+pre+cur; // 点数i 已经使用的数量
                    
                    if(used<=cnt[i])
                    {
                        int remain=cnt[i]-used;

                        if(dp[i-1][pre_pre][pre]>=0)
                        {
                            dp[i][pre][cur]=max(dp[i][pre][cur],dp[i-1][pre_pre][pre]+b*cur+(remain/3)*a);
                        }
                    }
                }
            }
        }
    }

    cout<<dp[13][0][0]<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}
