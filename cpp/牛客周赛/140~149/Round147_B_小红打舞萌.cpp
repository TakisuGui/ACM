#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{   
    int n; cin>>n;
    int cnt=n/5;
    int ans=0;
    if(cnt%2==0) ans=cnt*7/2;
    else ans=(cnt/2*3)+(cnt-cnt/2)*4;

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