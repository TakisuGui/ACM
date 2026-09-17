#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main()
{
    int h,w; cin>>h>>w;
    vector<string>line(h);
    for(int i=0;i<h;i++) cin>>line[i];

    vector<vector<bool>> visited(h,vector<bool>(w,false));

    int ans=0;

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(line[i][j]=='.'&&!visited[i][j])
            {
                queue<pair<int,int>>q;
                q.push({i,j});
                visited[i][j]=true;
                bool touch_boundary=false;
                if(i==0||i==h-1||j==0||j==w-1) touch_boundary=true;

                while(!q.empty())
                {
                    auto[x,y]=q.front(); q.pop();

                    for(int k=0;k<4;k++)
                    {
                        int nx=x+dx[k]; int ny=y+dy[k];
                        if(nx>=0&&nx<h&&ny>=0&&ny<w&&line[nx][ny]=='.'&&!visited[nx][ny])
                        {
                            visited[nx][ny]=true;
                            if(nx==0||nx==h-1||ny==0||ny==w-1) touch_boundary=true;
                            q.push({nx,ny});
                        }
                    }
                }

                if(!touch_boundary) ans++;
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}