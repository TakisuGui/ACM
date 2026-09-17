#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e18;
const int MOD=1e7+7;


void solve()
{
    int n; cin>>n;
    vector<int> a(n);
    int max_=-1;
    for(int i=1;i<=n;i++) cin>>a[i],max_=max(max_,a[i]);
    int x=__gcd(a[1],a[2]);
    for(int i=3;i<=n;i++) x=__gcd(x,a[i]);

    int k=max_/x;
    int t=k-n;

    if(t%2==1) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
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