#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll a[N],b[N];

void solve()
{
    int n; cin>>n;
    ll ans=-1e18;
    ll m=1e18;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i]-i;
        m=min(m,b[i]);
        ans=max(ans,b[i]-m);
    }
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i]+i;
        m=max(m,b[i]);
        ans=max(ans,m-b[i]);
    }

    cout<<ans<<endl;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; 
    if(!(cin >> t)) return 0;
    while(t--)
    {
        solve();
    }

    return 0;
}