#include<bits/stdc++.h>
using namespace std;

const int N=15;

//定义方向向量
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int arr[N][N];


int main(){

    int n;cin>>n;

    int x=1,y=1;
    int cnt=1;//当前要填的数
    int pos=0;

    while(cnt<=n*n)
    {
        arr[x][y]=cnt;

        int a=x+dx[pos],b=y+dy[pos];

        if(a>n||b>n||a<1||b<1||arr[a][b]!=0)
        {
            pos=(pos+1)%4;

            a=x+dx[pos],b=y+dy[pos];
        }

        x=a;y=b;
        cnt++;

    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%3d",arr[i][j]);
        }

        cout<<endl;
    }


    return 0;
}