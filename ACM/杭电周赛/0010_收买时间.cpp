#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF=1e9;
const int dx[4]={-1, 1, 0, 0};
const int dy[4]={0, 0, -1, 1};


bool check(int mid,int n,int m,int money,vector<vector<int>>& t,vector<vector<vector<tuple<int,int,int>>>>& portals_from)
{
    queue<tuple<int,int,int>> q;
    vector<vector<int>> min_cost(n+1,vector<int>(m+1,INF));

    if(t[1][1]>mid) return false;

    min_cost[1][1]=0;
    q.push({1,1,0});

    while(!q.empty())
    {
        auto [x,y,cost]=q.front(); q.pop();

        if(cost>min_cost[x][y]) continue;
        if(x==n&&y==m) return true;

        for(int d=0;d<=3;d++)
        {
            int nx=x+dx[d]; int ny=y+dy[d];
            if(nx<1||nx>n||ny<1||ny>m) continue;
            if(t[nx][ny]>mid) continue;

            if(min_cost[nx][ny]>cost)
            {
                min_cost[nx][ny]=cost;
                q.push({nx,ny,cost});
            }
        }

        for(auto& [tx,ty,w]:portals_from[x][y])
        {
            if(t[tx][ty]>mid) continue;

            int new_cost=cost+w;
            if(new_cost<=money&&min_cost[tx][ty]>new_cost)
            {
                min_cost[tx][ty]=new_cost;
                q.push({tx,ty,new_cost});
            }
        }
    }

    return min_cost[n][m]<=money;
}

void slove()
{
    int n,m,money,k; cin>>n>>m>>money>>k;

    vector<vector<int>> t(n+1,vector<int>(m+1));
    int max_t=0; //可以经历的最长时间
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>t[i][j]; //获取每一个格子可以通行的时间
            max_t=max(max_t,t[i][j]);
        }
    }

    vector<vector<vector<tuple<int,int,int>>>> portals_from(n+1,vector<vector<tuple<int,int,int>>>(m+1));
    /*第一维是行,第二是列,第三维是同一个起点不同终点的门,tuple里面分别对应 终点行坐标,终点列坐标,使用门的代价*/

    for(int i=1;i<=k;i++)
    {
        int x,y,p,q,w; cin>>x>>y>>p>>q>>w;
        portals_from[x][y].push_back({p,q,w});
    }

    int left=0,right=max_t,ans=-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(check(mid,n,m,money,t,portals_from))
        {
            right=mid-1;
            ans=mid;
        }
        else left=mid+1;
    }

    cout<<ans<<endl;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T;
    while(T--)
    {
        slove();
    }

    return 0;
}