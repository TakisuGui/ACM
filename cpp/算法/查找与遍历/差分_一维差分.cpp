#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10; 

int n,m;
int a[N];
int f[N];

int main()
{
    cin>>n>>m;
    //利用定义创建
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=a[i]-a[i-1];
    }


    // 利用性质创建
    for(int i=1;i<+n;i++)
    {
        int x;cin>>x;
        f[i]+=x;
        f[i+1]-=x;
    }


    //处理m次操作
    while(m--)
    {
        int l,r,k;cin>>l>>r>>k;
        f[l]+=k;f[r+1]-=k;
    }

    //还原数组
    for(int i=1;i<=n;i++)
    {
        a[i]=f[i]+a[i-1];//f[i]=f[i-1]+f[i];
        cout<<a[i]<<endl;//cout<<f[i]<<endl;
    }


    return 0;
}