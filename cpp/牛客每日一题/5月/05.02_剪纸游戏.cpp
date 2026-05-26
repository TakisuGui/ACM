#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=1e3+10;
const int M=1e6+10;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool vis[N][N];
int max_x[M],max_y[M],min_x[M],min_y[M];

void solve()
{
    int n,m; cin>>n>>m;
    vector<string> text(n);

    for(int i=0;i<n;i++) cin>>text[i];
    int cnt=0;
    

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j]&&text[i][j]=='.')
            {
                queue<pair<int,int>> q;
                q.push({i,j});
                vis[i][j]=true;
                cnt++;
                max_x[cnt]=i,max_y[cnt]=j,min_x[cnt]=i,min_y[cnt]=j;
                
                while(!q.empty())
                {
                    auto[x,y]=q.front(); q.pop();

                    for(int k=0;k<4;k++)
                    {
                        int nx=dx[k]+x,ny=dy[k]+y;
                        if(nx<0||nx>n-1||ny<0||ny>m-1||vis[nx][ny]||text[nx][ny]!='.') continue;

                        vis[nx][ny]=true;
                        q.push({nx,ny});

                        max_x[cnt]=max(max_x[cnt],nx);
                        max_y[cnt]=max(max_y[cnt],ny);
                        min_x[cnt]=min(min_x[cnt],nx);
                        min_y[cnt]=min(min_y[cnt],ny);
                    }
                }
            }
        }
    }


    int ans=0;
    for(int k=1;k<=cnt;k++)
    {
        bool pass=true;
        
        for(int i=min_x[k];i<=max_x[k];i++)
        {
            if(text[i][min_y[k]]!='.'||text[i][max_y[k]]!='.')
            {
                pass=false;
                break;
            }
        }

        for(int j=min_y[k];j<=max_y[k];j++)
        {
            if(text[min_x[k]][j]!='.'||text[max_x[k]][j]!='.')
            {
                pass=false;
                break;
            }
        }

        if(pass) ans++;
    }

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