#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll


void solve()
{
    int n; cin>>n;
    int ans=0;

    for(int b=1;b*b<=n;b++)
    {
        int p=b*(b+1);
        int full=(n+1)/p;

        ans+=full*b;

        int start=(full+1)*p-b;
        if(start<=n) ans+=min(b,n-start+1);
    }
    cout<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}