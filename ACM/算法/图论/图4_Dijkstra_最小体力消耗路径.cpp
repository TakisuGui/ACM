#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<pair<int,pair<int,int>>> edges[105][105];
    int a[105][105];
    bool visited[105][105];
    int dx[4]={0,1,-1,0};
    int dy[4]={1,0,0,-1};
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> heap_small;//小跟堆

    int minimumEffortPath(vector<vector<int>>& heights) {

        int rows=heights.size(),columns=heights[0].size();

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
            {
                edges[i][j].clear();
                a[i][j]=2e9;
                visited[i][j]=false;
            }
        }


        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
            {
                for(int k=0;k<4;k++)
                {
                    int nx=i+dx[k],ny=j+dy[k];
                    if(nx<0||nx>=rows||ny<0||ny>=columns) continue;

                    int cost=abs(heights[nx][ny]-heights[i][j]);
                    edges[i][j].push_back({cost,{nx,ny}});
                }
            }
        }

        heap_small.push({0,{0,0}}); a[0][0]=0;

        while(!heap_small.empty())
        {
            auto use=heap_small.top(); heap_small.pop();
            int dis=use.first,fx=use.second.first,fy=use.second.second;

            if(visited[fx][fy]) continue;
            visited[fx][fy]=true;

            for(auto have:edges[fx][fy])
            {
                int w=have.first,ix=have.second.first,iy=have.second.second;

                int cur_effort=max(dis,w);  //到上一个点的体力消耗 , 这一步的高度差
                if(a[ix][iy]>cur_effort)
                {
                    a[ix][iy]=cur_effort;
                    heap_small.push({a[ix][iy],{ix,iy}});
                }
            }
        }

       return a[rows-1][columns-1];
    }
};