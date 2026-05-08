#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e6+10;

int dp[51][51][2501];
int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}

void solve()
{
    int n,m,x; cin>>n>>m>>x;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int k=0;k<=x;k++)
                dp[i][j][k]=-1;
    
    for(int v=1;v<=m;v++)
    {
        if(v<=x) dp[1][v][v]=0;
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=1;k<=x;k++)
            {
                if(dp[i][j][k]==-1) continue;

                for(int v=1;v<=m;v++)
                {
                    int g=gcd(j,v);
                    int nextsum=k+g;
                    
                    if(nextsum<=x) dp[i+1][g][nextsum]=j;
                }
            }
        }
    }

    int lastgcd=-1;
    for(int j=1;j<=m;j++)
    {
        if(dp[n][j][x]!=-1)
        {
            lastgcd=j;
            break;
        }
    }

    if(lastgcd==-1){cout<<"-1"<<endl; return;}

    vector<int> ans;
    int curgcd=lastgcd;
    int cursum=x;

    for(int i=n;i>=1;i--)
    {
        ans.push_back(curgcd);
        int pre_gcd=dp[i][curgcd][cursum];
        cursum-=curgcd;
        curgcd=pre_gcd;
    }

    for(int i=n-1;i>=0;i--) cout<<ans[i]<<" ";
    cout<<endl;
}


signed main()
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