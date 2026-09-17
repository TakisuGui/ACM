#include<bits/stdc++.h>
using namespace std;

const int N=400+10;

typedef pair<int,int>PII;

int n,m,x,y;
int dis[N][N];

//偏移坐标
int dx[8]={1,2,2,1,-1,-2,-2,-1};
int dy[8]={2,1,-1,-2,-2,-1,1,2};

void bfs()
{
    //初始化
    memset(dis,-1,sizeof dis);

    queue<PII> q;

    q.push({x,y});
    dis[x][y]=0;

    while(!q.empty())
    {
        auto temp=q.front(); q.pop();
        int i=temp.first;int j=temp.second;

        for(int re=0;re<=7;re++)
        {
            int x_new=i+dx[re];int y_new=j+dy[re];

            if(x_new<1||x_new>n||y_new<1||y_new>m)continue;

            if(dis[x_new][y_new]!=-1)continue;

            dis[x_new][y_new]=dis[i][j]+1;

            q.push({x_new,y_new});
        }
    }
}

int main()
{
    cin>>n>>m>>x>>y;

    bfs();

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<dis[i][j]<<" ";
        }

        cout<<endl;
    }
}