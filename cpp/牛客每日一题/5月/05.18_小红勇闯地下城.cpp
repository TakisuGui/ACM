#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void dijkstra(int n,int m,int sx,int sy,vector<string>& mp,vector<vector<int>>& dis,vector<vector<bool>>& vis)
{
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> heap_small;
    dis[sx][sy]=0; heap_small.push({0,{sx,sy}});

    while(!heap_small.empty())
    {
        auto use=heap_small.top(); heap_small.pop();
        int v=use.first,cur_x=use.second.first,cur_y=use.second.second;

        if(vis[cur_x][cur_y]) continue;
        vis[cur_x][cur_y]=true;

        for(int i=0;i<4;i++)
        {
            int nx=cur_x+dx[i],ny=cur_y+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;

            if(dis[nx][ny]>v+(mp[nx][ny]-'0'))
            {
                dis[nx][ny]=v+(mp[nx][ny]-'0');
                heap_small.push({dis[nx][ny],{nx,ny}});
            }
        }
    }
}

void solve()
{
    int n,m,h; cin>>n>>m>>h;
    vector<string> mp(n);
    for(int i=0;i<n;i++) cin>>mp[i];
    vector<vector<int>> dis(n,vector<int>(m,LONG_LONG_MAX));
    vector<vector<bool>> vis(n,vector<bool>(m,false));

    int sx,sy,tx,ty;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mp[i][j]=='S')
            {
                sx=i,sy=j;
                mp[i][j]='0';
            }
            if(mp[i][j]=='T')
            {
                tx=i,ty=j;
                mp[i][j]='0';
            }
        }
    }

    dijkstra(n,m,sx,sy,mp,dis,vis);

    cout<<(dis[tx][ty]<h ? "Yes" : "No")<<endl;
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