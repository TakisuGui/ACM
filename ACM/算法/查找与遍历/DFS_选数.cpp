#include<bits/stdc++.h>
using namespace std;

const int N=25;
int n,k;
int a[N];

int sum;
int path;

bool isp(int x)
{
    if(x<=1)return false;
    for(int i=2;i<=x/i;i++)
    {
        if(x%i==0)return false;

    }
    return true;
}

void dfs(int place,int begin)
{
    if(place>k)
    {
        if(isp(path))sum++;
        return;
    }
    
    for(int i=1;i<=n;i++)
    {
        path+=a[i];
        dfs(place+1,i+1);
        path-=a[i];

    }
}

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];

    dfs(1,1);

    cout<<sum<<endl;

    return 0;
}