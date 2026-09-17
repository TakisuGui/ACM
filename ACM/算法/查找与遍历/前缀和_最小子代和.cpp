#include<iostream>
using namespace std;

typedef long long LL;

const int N=1e5+10;

LL f[N];
int n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        LL x;cin>>x;
        f[i]=f[i-1]+x;
    }

    LL ans=-1e20;
    LL small=0;

    for(int i=1;i<=n;i++)
    {
        ans=max(ans,f[i]-small);
        small=min(small,f[i]);

    }
    cout<<ans<<endl;
}