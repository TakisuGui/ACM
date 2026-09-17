#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll


void solve()
{
    int n; cin>>n;
    vector<int> a(n+1);
    vector<int> pre(n+1,0);

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }

    ll ans=0;
    for(int i=2;i<=n;i++)
    {
        ans+=((i-1)*a[i]-pre[i-1]);
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