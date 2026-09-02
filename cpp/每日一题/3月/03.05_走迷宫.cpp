#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e3+10;

int n,m;
int xs,ys,xt,yt;
char text[N][N];
int dis[N][N];
bool pass[N][N];
bool find_ans;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void bfs(int xs,int ys)
{
    queue<pair<int,int>> pass_way;
    pass_way.push({xs,ys});
    dis[xs][ys]=0;
    pass[xs][ys]=true;
    
    while(!pass_way.empty())
    {
        int current_x=pass_way.front().first;
        int current_y=pass_way.front().second;
        pass_way.pop();

        if(current_x==xt&&current_y==yt)
        {
            cout<<dis[current_x][current_y]<<endl;
            find_ans=true;
            return;
        }


        for(int k=0;k<4;k++)
        {
            int nx=current_x+dx[k],ny=current_y+dy[k];
            if(text[nx][ny]!='*'&&nx>=1&&nx<=n&&ny>=1&&ny<=m&&!pass[nx][ny])
            {
                dis[nx][ny]=dis[current_x][current_y]+1;
                pass[nx][ny]=true;

                pass_way.push({nx,ny});
            }

        }
    }
}

int main()
{
    cin>>n>>m;
    cin>>xs>>ys>>xt>>yt;


    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>text[i][j];

    bfs(xs,ys);


    if(!find_ans)cout<<-1<<endl;

    return 0;
}
