#include<bits/stdc++.h>
using namespace std;

int n;
int f[35];

int dfs(int n)
{
    if(f[n]!=-1)return f[n];

    if(n==1||n==0)return n;

    f[n]=dfs(n-1)+dfs(n-2);

    return f[n];

}


int main()
{
    cin>>n;

    memset(f,-1,sizeof f);

    cout<<dfs(n)<<endl;

    return 0;
}