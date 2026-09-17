#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{
    int a,b; cin>>a>>b;
    if(a>b) swap(a,b);

    int ans;
    if(min(a,b)>1) ans=1;
    else
    {
        if(b==1) ans=2;
        else if(b==2) ans=3;
        else ans=2;
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