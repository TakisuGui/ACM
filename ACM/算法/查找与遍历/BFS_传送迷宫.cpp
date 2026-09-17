#include <bits/stdc++.h>
using namespace std;

const int INF=1e9;
int H,W;
bool found=false;
vector<string> row;

//创建传送门
vector< vector< pair<int,int> > > door(26);

//创建偏移向量
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


void bfs()
{
    //记录最短距离
    vector< vector<int> > distance(H);//二维数组
    for(int q=0;q<H;q++) distance[q]=vector<int>(W,INF);//初始化

    //已使用的门
    vector<bool> used_door(26,false);

    queue<pair<int,int>> pass;

    distance[0][0]=0;
    pass.push({0,0});
    while(!pass.empty())
    {
        pair<int,int>current=pass.front();
        pass.pop();
        int now_x=current.first;
        int now_y=current.second;

        //到达终点
        if(now_x==H-1&&now_y==W-1)
        {
            cout<<distance[now_x][now_y]<<endl;
            found=true;
            return ;
        }

        //移动
        for(int move=0;move<4;move++)
        {
            int new_x=now_x+dx[move];
            int new_y=now_y+dy[move];

            if(new_x>=0&&new_x<H&&new_y>=0&&new_y<W&&row[new_x][new_y]!='#')
            {
                if(distance[new_x][new_y]>distance[now_x][now_y]+1)
                {
                    distance[new_x][new_y]=distance[now_x][now_y]+1;
                    pass.push({new_x,new_y});
                }
            }

        }

        //传送
        if(row[now_x][now_y]>='a'&&row[now_x][now_y]<='z')
        {
            int index=row[now_x][now_y]-'a';

            if(!used_door[index])
            {
                used_door[index]=true;

                for(auto pos: door[index])
                {
                    int new_x=pos.first;
                    int new_y=pos.second;

                    if(distance[new_x][new_y]>distance[now_x][now_y]+1)
                    {
                        distance[new_x][new_y]=distance[now_x][now_y]+1;
                        pass.push({new_x,new_y});
                    }
                }
            }
           
        }
        
    }

}


int main()
{
    cin>>H>>W;

    //输入每一行
    for(int i=0;i<H;i++)
    {
        string line;cin>>line;
        row.push_back(line);
    }

    //遍历找到传送门
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            if(row[i][j]>='a'&&row[i][j]<='z')
            {
                door[row[i][j]-'a'].emplace_back(i,j);
            }
        }
    }

    bfs();

    if(found==false)cout<<-1<<endl;

    return 0;

}