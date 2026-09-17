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
    vector<int> a(n+1);
    int sum=0; int max_=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i],sum+=a[i];
        max_=max(max_,a[i]);
    }

    if(sum%2==1) cout<<(max_+1)/2<<endl;
    else cout<<max_/2<<endl;
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