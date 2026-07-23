#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll



void solve()
{
    int n,x; cin>>n>>x;
    int ans=n;
    for(int i=1;i<=x;i++)
    {
        int x,y; cin>>x>>y;
        if(n>=x) ans=min(ans,n-y);
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