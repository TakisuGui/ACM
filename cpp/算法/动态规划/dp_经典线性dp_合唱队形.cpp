#include<bits/stdc++.h>
using namespace std;

const int N=110;
int a[N];
int dp_up[N],dp_down[N];
int n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dp_down[i]=1;
        dp_up[i]=1;
    }

    int max_len=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(a[j]<a[i]) dp_up[i]=max(dp_up[i],dp_up[j]+1);
        }
    }

    for(int i=n;i>=1;i--)
    {
        for(int j=n;j>i;j--)
        {
            if(a[i]>a[j]) dp_down[i]=max(dp_down[i],dp_down[j]+1);
        }
    }

    for(int i=1;i<=n;i++)
    max_len=max(max_len,dp_down[i]+dp_up[i]-1);

    cout<<n-max_len<<endl;

    return 0;
}