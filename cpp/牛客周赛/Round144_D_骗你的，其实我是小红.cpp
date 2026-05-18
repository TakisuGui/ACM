#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{
    int l,r,k; cin>>l>>r>>k;

    int length=(r-l)+1;
    int a=length/k;
    int surplus=length%k;

    int ans=surplus*(a+1)*a/2+(k-surplus)*a*(a-1)/2;

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