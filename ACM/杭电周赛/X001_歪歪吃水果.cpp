#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve() 
{
    int a,b,n,m; cin>>a>>b>>n>>m;
    int k=n/m;

    cout<<(a>=k*k&&b>=k*k ? "YES" :"NO")<<endl;
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