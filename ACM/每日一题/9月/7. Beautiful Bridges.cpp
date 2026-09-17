#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int INF=1e18;

struct Point
{
    int x,y;
};

void solve()
{
    int n; double h; int alpha,beta; cin>>n>>h>>alpha>>beta;
    vector<Point> p(n+1);
    for(int i=1;i<=n;i++) cin>>p[i].x>>p[i].y;

    vector<double> lmax(n+1),rmax(n+1);
    for(int i=1;i<=n;i++)
    {
        lmax[i]=min((p[n].x-p[i].x)/2.0,h-p[i].y);
        for(int j=i+1;j<=n;j++)
        {
            if((p[j].x-p[i].x)>lmax[i]) break;
            double dy=h-p[j].y;
            double dx=p[j].x-p[i].x;

            double lim=max(dy,dx+dy+sqrt(2.0*dx*dy));
            lmax[i]=min(lmax[i],lim);
        }
    }
    for(int i=1;i<=n;i++)
    {
        rmax[i]=min((p[i].x-p[1].x)/2.0,h-p[i].y);
        for(int j=i-1;j>=1;j--)
        {
            if((p[i].x-p[j].x)>rmax[i]) break;
            double dy=h-p[j].y;
            double dx=p[i].x-p[j].x;

            double lim=max(dy,dx+dy+sqrt(2.0*dx*dy));
            rmax[i]=min(rmax[i],lim);
        }
    }

    vector<int> dp(n+1,INF);
    dp[1]=alpha*(h-p[1].y);
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(dp[j]>=INF) continue;
            double d=p[i].x-p[j].x;
            double r=d/2.0;

            if (r>lmax[j]+1e-9) continue;
            if (r>rmax[i]+1e-9) continue;

            int cost=dp[j]+(alpha*(h-p[i].y)+beta*d*d);
            dp[i]=min(dp[i],cost);
        }
    }

    if(dp[n]>=INF) cout<<"impossible"<<endl;
    else cout<<dp[n]<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}