#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e9+7;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

struct Point
{
    int x; int y;
    int h;
};

void solve()
{
    int n,m; cin>>n>>m;
    vector<vector<int>> h(n,vector<int>(m,0));
    vector<Point> p;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin>>h[i][j];
            p.push_back({i,j,h[i][j]});
        }

    sort(p.begin(),p.end(),[](const Point& a,const Point& b)
    {
        return a.h>b.h;
    });

    vector<vector<bool>> win(n,vector<bool>(m,0));

    for(const auto& v : p)
    {
        int cx=v.x,cy=v.y;

        for(int k=0;k<4;k++)
        {
            int nx=cx+dx[k],ny=cy+dy[k];
            if (nx<0||ny<0||nx>=n||ny>=m) continue;

            if(h[nx][ny]>h[cx][cy])
            {
                if(!win[nx][ny])
                {
                    win[cx][cy]=true;
                    break;
                }
            }
        }
    }

    int q; cin>>q;
    while(q--)
    {
        int r,c; cin>>r>>c; r--; c--;
        cout<<(win[r][c] ? "First" : "Second")<<endl;
    }
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
