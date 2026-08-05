#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e7+7;


void solve()
{
    vector<int> a(3);
    for(int i=0;i<3;i++) cin>>a[i];
    sort(a.begin(),a.end());

    int ans=min(a[1]-a[0],a[2]-a[1]);
    cout<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}