#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=3e5+10;

void solve()
{
    int n,m; cin>>n>>m;
    int ans=0;

    while(m!=0)
    {
        int cur=n%m;
        m=cur;
        ans++;
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