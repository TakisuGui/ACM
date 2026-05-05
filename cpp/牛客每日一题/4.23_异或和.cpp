#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve()
{

    ll ans=0;
    ll n; cin>>n;

    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        ans^=x;
    }

    cout<<ans<<endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}