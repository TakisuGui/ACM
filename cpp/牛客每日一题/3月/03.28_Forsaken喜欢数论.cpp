#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=3e7+10;
int f[N];

int main()
{
    int n; cin>>n;

    f[1]=0;
    for(int i=2;i<=n;i++)
    {
        if(f[i]) continue;
        for(int j=i;j<=n;j+=i) if(!f[j]) f[j]=i;
    }
    ll ans=0;
    for(int i=1;i<=n;i++) ans+=f[i];
    cout<<ans<<endl;

    return 0;
}