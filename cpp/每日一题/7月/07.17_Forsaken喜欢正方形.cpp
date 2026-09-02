#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
struct Point { ll x,y;};
ll getdis(Point p1, Point p2){ return(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);}

bool sq(Point a,Point b,Point c,Point d)
{
    vector<ll> dis(6);
    dis[0]=getdis(a,b);
    dis[1]=getdis(a,c);
    dis[2]=getdis(a,d);
    dis[3]=getdis(b,c);
    dis[4]=getdis(b,d);
    dis[5]=getdis(c,d);

    sort(dis.begin(),dis.end());

    return (dis[0]>0 &&
            dis[0]==dis[1]&&dis[1]==dis[2]&&dis[2]==dis[3] &&
            dis[4]==dis[5] &&
            dis[4]==dis[0]*2);
}


void solve()
{
    Point p[4];
    cin>>p[0].x>>p[0].y>>p[1].x>>p[1].y>>p[2].x>>p[2].y>>p[3].x>>p[3].y;
    if(sq(p[0],p[1],p[2],p[3]))
    {
        cout<<"wen"<<endl;
        return;
    }

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            Point new_p={p[j].x+dx[i],p[j].y+dy[i]};
            if(sq(new_p,p[(j+1)%4],p[(j+2)%4],p[(j+3)%4]))
            {
                cout<<"hai xing"<<endl;
                return;
            }
        }
    }
    
    cout<<"wo jue de bu xing"<<endl;
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