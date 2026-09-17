#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{
    int n,x,y; cin>>n>>x>>y;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    int g=__gcd(x,y);
    for(int i=1;i<=n;i++)
    {
        if((i%g)!=(a[i]%g)) { cout<<"NO"<<endl; return;}
    }
    
    cout<<"YES"<<endl;
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

