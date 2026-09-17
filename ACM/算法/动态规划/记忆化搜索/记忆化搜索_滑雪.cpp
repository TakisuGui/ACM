#include<bits/stdc++.h>
using namespace std;

const int N=105;
int r,c;
int tep[N][N];
int a[N][N];

int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};

int dfs(int i,int j)
{
    if(tep[i][j]!=0) return tep[i][j];

    tep[i][j]=1;

    for(int q=0;q<4;q++)
    {
        int new_i=i+dx[q];
        int new_j=j+dy[q];

        if(new_i>=1&&new_i<=r&&new_j>=1&&new_j<=c&&a[i][j]>a[new_i][new_j])
        {
            tep[i][j]=max(tep[i][j],dfs(new_i,new_j)+1);
        }
    }

    return tep[i][j];

}


int main()
{
    cin>>r>>c;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            cin>>a[i][j];
        }
    }

    int ans=0;
    memset(tep,0,sizeof tep);

    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            ans=max(ans,dfs(i,j));
        }
    }

    cout<<ans<<endl;
    return 0;
}
