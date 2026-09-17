#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll


void solve()
{
    int n,m,a,b; cin>>n>>m>>a>>b;

    int ans=0;
    int t=min(n/2,m);
    for(int i=0;i<=t;i++)
    {
        int q=min(n-2*i,(m-i)/2);
        ans=max(ans,i*a+q*b);
    }

    cout<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}