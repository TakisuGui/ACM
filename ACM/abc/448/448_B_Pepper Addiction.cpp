#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
int c[1010];

int main()
{
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int x; cin>>x;
        c[i]=x;
    }

    ll ans=0;

    while(n--)
    {
        int p,q; cin>>p>>q;
        if(c[p]-q>=0)
        {
            c[p]-=q;
            ans+=q;
        }
        else if(c[p]==0) continue;
        else if(c[p]-q<0)
        {
            ans+=c[p];
            c[p]=0;
        }
    }

    cout<<ans<<endl;

    return 0;
}