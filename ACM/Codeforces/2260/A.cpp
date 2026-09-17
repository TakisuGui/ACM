#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=998244353;


void solve()
{
    int n; cin>>n;
    vector<int> a(n);
    int cnt_0=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==0) cnt_0++;
    }

    if(cnt_0<2)
    {
        cout<<-1<<endl;
        return;
    }

    int ans=0;
    if(a[0]==1) ans++;
    if(a[n-1]==1) ans++;
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