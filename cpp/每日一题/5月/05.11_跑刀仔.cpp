#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

vector<pair<pair<double,double>,double>> cur(11);
double epslon=1e-6;
double delta=1e-3;
int n,l;

double dis(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

bool check(double x,double y,vector<pair<pair<double,double>,double>>& cur)
{
    if(x<0||x>l||y<0||y>l)return false;
    for(auto v : cur)
    {
        if(dis(v.first.first,v.first.second,x,y)<=v.second+epslon) return false;
    }

    return true;
}

void solve()
{
    cin>>n>>l;
    for(int i=1;i<=n;i++)
    {
        double x,y,r; cin>>x>>y>>r;
        cur[i].first.first=x,cur[i].first.second=y,cur[i].second=r;
    }

    for(int i=1;i<=n;i++)
    {
        double a=cur[i].first.first,b=cur[i].first.second,c=cur[i].second;
        for(int j=1;j<=359000;j++)
        {
            double cur_x=a+c*cos(j/1000.0)+delta;
            double cur_y=b+c*sin(j/1000.0)+delta;

            if(check(cur_x,cur_y,cur)) 
            {
                printf("%lf %lf\n",cur_x,cur_y);
                return;
            }
        }
    }
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