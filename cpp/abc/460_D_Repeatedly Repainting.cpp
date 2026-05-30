#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
#define rep(i, n) for(int i=0; i<(n);i++)
const int N=3e5+10;
const int inf=1000000010;
int dx[8]={1,0,-1,0,1,-1,-1,1};
int dy[8]={0,1,0,-1,1,1,-1,-1};

int n,m;
bool in(int x,int y)
{
    return 0<=x&&x<n&&0<=y&&y<m;
}

void solve()
{
    cin>>n>>m;
    vector<string> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<string> b(n,string(m, '.'));
    rep(i,n) rep(j,m)
    {
        if(a[i][j]=='#')
        {
            rep(d,8)
            {
                int nx=i+dx[d],ny=j+dy[d];
                if(in(nx,ny)&&a[nx][ny]=='.') b[nx][ny]='#';
            }
        }
    }
    a=move(b);

    vector D(n,vector<int>(m,inf));
    queue<pair<int,int>> q;

    rep(i,n) rep(j,m) if(a[i][j] == '#') {D[i][j] = 0; q.push({i,j});}

    while(!q.empty())
    {
        auto[i,j]=q.front(); q.pop();
        rep(k,8)
        {
            int nx=i+dx[k],ny=j+dy[k];
            if(in(nx,ny)&&D[nx][ny]==inf)
            {
                D[nx][ny]=D[i][j]+1;
                q.push({nx,ny});
            }
        }
    }
    
    rep(i,n)
    {
        rep(j,m) a[i][j]= (D[i][j]%2==0 ? '.' : '#');
        cout<<a[i]<<endl;
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