#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=20;

int graph[N][N];
int n;
int dp[1<<20][20];// 1:已经到达过 0:未到达过

//f : 要走完所有还没去过的村庄,最后回到起点村庄0,所需要的最短路径长度
int f(int status,int i) // i:目前在哪个村
{
    if(status==(1<<n)-1) return graph[i][0];
    if(dp[status][i]!=-1) return dp[status][i];

    int ans=LONG_LONG_MAX;
    for(int j=0;j<n;j++)
    {
        if( (status&(1<<j))==0 )
        {
            ans=min(ans,graph[i][j]+f(status|(1<<j),j));
        }
    }
    dp[status][i]=ans;

    return ans;
}

void solve()
{
    cin>>n;
    memset(dp,-1,sizeof(dp));

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>graph[i][j];
    
    cout<<f(1,0)<<endl;
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