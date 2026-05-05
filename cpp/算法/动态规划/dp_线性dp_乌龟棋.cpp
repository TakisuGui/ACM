#include<bits/stdc++.h>
using namespace std;

const int N=45;

int n,m;
int dp[N][N][N][N];
int pos;
int score[360];
int cnt[5];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>score[i];

    memset(cnt,0,sizeof cnt);
    for(int i=1;i<=m;i++)
    {
        int x;cin>>x;
        cnt[x]++;
    }

    dp[0][0][0][0]=score[1];

    for(int a=0;a<=cnt[1];a++)
    {
        for(int b=0;b<=cnt[2];b++)
        {
            for(int c=0;c<=cnt[3];c++)
            {
                for(int d=0;d<=cnt[4];d++)
                {
                    pos=1+1*a+2*b+3*c+4*d;
                    if(pos>n) continue;

                    if(a>0) dp[a][b][c][d]=max(dp[a][b][c][d],dp[a-1][b][c][d]+score[pos]);
                    if(b>0) dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b-1][c][d]+score[pos]);
                    if(c>0) dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b][c-1][d]+score[pos]);
                    if(d>0) dp[a][b][c][d]=max(dp[a][b][c][d],dp[a][b][c][d-1]+score[pos]);
                }
            }
        }
    }

    cout<<dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]]<<endl;

    return 0;
}