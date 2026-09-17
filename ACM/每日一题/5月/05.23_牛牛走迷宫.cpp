#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

int dx[4]={1,0,-0,-1};
int dy[4]={0,-1,1,0};
char dc[4]={'D','L','R','U'};

struct step
{
    string way;
    int dis;
    int x,y;
};


void solve()
{
    int n,m; cin>>n>>m;
    vector<string> s(n+1);
    vector<vector<bool>> vis(n+1,vector<bool>(m+1,false));
    for(int i=1;i<=n;i++) { string ss; cin>>ss; s[i]=' '+ss; }

    queue<step> q;
    q.push({"",0,1,1});
    vis[1][1]=true;

    while(!q.empty())
    {
        auto [way,dis,x,y]=q.front(); q.pop();

        if(x==n&&y==m)
        {
            cout<<dis<<endl;
            cout<<way<<endl;
            return;
        }

        for(int k=0;k<4;k++)
        {
            int nx=x+dx[k],ny=y+dy[k];

            if(nx<1||nx>n||ny<1||ny>m||vis[nx][ny]||s[nx][ny]=='1') continue;

            vis[nx][ny]=true;
            q.push({way+dc[k],dis+1,nx,ny});
        }
    }

    cout<<-1<<endl;
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