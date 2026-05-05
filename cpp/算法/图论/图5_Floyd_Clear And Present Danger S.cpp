#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=105;
const int M=1e4+10;

int dis[N][N];
int pass[M];

void solve()
{
    int n,m; cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>pass[i];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) 
            cin>>dis[i][j];


    for(int brige=1;brige<=n;brige++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][brige]+dis[brige][j]);
            }
        }
    }
    
    ll ans=0;
    for(int i=2;i<=m;i++) ans+=dis[pass[i-1]][pass[i]];
    
    cout<<ans<<endl;
}


int main()
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