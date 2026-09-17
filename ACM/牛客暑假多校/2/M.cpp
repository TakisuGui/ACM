#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e9+7;


void solve()
{
    int n,m; cin>>n>>m;
    int sum=n*(n-1)/2;

    int ans;
    if(m>=n-1) ans=sum-m;
    else
    {
        ans=sum-m;
        for(int i=n-1;i>m;i--) ans-=i;
    }

    cout<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}
