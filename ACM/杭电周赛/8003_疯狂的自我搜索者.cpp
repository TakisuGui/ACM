#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{
    int n,x; cin>>n>>x;
    int ans=0;

    for(int i=1;i<=n;i++)
    {
        int a; cin>>a;
        ans=(a+ans-x>0) ? a+ans-x : 0;
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