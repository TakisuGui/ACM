#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=10;

int a,b;
bool pass[N][N];
int ans;

int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};

void dfs(int i,int j)
{
    if(i<1||i>=a||j<1||j>=b)
    {
        ans++;
        return;
    }
    pass[i][j]=true;
    
    for(int k=0;k<4;k++)
    {
        int nx=dx[k]+i; int ny=dy[k]+j;

        if(!pass[nx][ny])dfs(nx,ny);
    }
    pass[i][j]=false;
}

int main()
{
    cin>>a>>b;

    for(int j=1;j<b;j++)
    {
        pass[0][j]=true;
        dfs(1,j);
        pass[0][j]=false;
    }
    for(int i=1;i<a;i++)
    {
        pass[i][0]=true;
        dfs(i,1);
        pass[i][0]=false;
    }

    cout<<ans<<endl;

    return 0;
}