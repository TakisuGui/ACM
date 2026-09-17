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
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    vector<int> diff(n+2,0);
    for(int i=1;i<=n;i++)
    {
        ll l=i*a[i],r=min(i*(a[i]+1)-1,n-1);
        if(l>=n)continue;

        diff[l]+=1;
        diff[r+1]-=1;
    }

    vector<int> b;
    int cur=0;
    for(int x=0;x<n;x++)
    {
        cur+=diff[x];
        if(cur==0) b.push_back(x);
    }

    cout<<b.size()<<endl;
    for(auto& x : b) cout<<x<<" ";
    cout<<endl;
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