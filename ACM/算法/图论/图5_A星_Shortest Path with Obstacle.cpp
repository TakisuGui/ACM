#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

int a[1010][1010];
bool visited[1010][1010];
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};


int get_h(int x,int y,int tx,int ty){ return abs(x-tx)+abs(y-ty); }

void solve()
{
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> heap_small;//小跟堆

    int sx,sy; cin>>sx>>sy;
    int tx,ty; cin>>tx>>ty;

    for(int i=0;i<1005;i++)
    {
        for(int j=0;j<1005;j++)
        {
            a[i][j]=2e9;
            visited[i][j]=false;
        }
    }


    heap_small.push({0+get_h(sx,sy,tx,ty),{sx,sy}});
    a[sx][sy]=0;

    while(!heap_small.empty())
    {
        auto use=heap_small.top(); heap_small.pop();
        int dis=use.first,fx=use.second.first,fy=use.second.second;

        if(visited[fx][fy]) continue;
        visited[fx][fy]=true;

        if(fx==tx&&fy==ty)
        {
            cout<<a[fx][fy]<<endl;
            return;
        }

        for(int k=0;k<4;k++)
        {
            int ix=fx+dx[k],iy=fy+dy[k];
            if(ix<0||ix>1000||iy<0||iy>1000) continue;

            if(a[ix][iy]>a[fx][fy]+1)
            {
                a[ix][iy]=a[fx][fy]+1;
                heap_small.push({a[ix][iy]+get_h(ix,iy,tx,ty),{ix,iy}});
            }

        }
    }

}


int main()
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




// 测试输入 (Input)
// 5

// 1 1
// 3 3

// 10 10
// 10 10

// 1 1
// 1 10

// 5 5
// 1 1

// 100 100
// 500 500


// 预期输出 (Output)
// 4
// 0
// 9
// 8
// 800