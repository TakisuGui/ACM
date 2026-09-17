#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll


void solve()
{
    int n,m; cin>>n>>m;
    vector<int> a(2*n+1);
    for(int i=1;i<=2*n;i++) cin>>a[i];

    int ans1=0;
    int t=a[1]+m;
    if(t<a[2]) ans1++;

    for(int i=3;i<=2*n;i+=2)
    {
        if(a[i]<=t&&a[i+1]<=t&&a[i]+a[i+1]+m<=2*t){}
        else if(a[i]>t&&a[i+1]>t) ans1+=2;
        else ans1+=1;
    }

    int ans2=0;
    a[2]+=m;
    if(a[1]<a[2]) ans2++;

    for(int i=3;i<=2*n;i+=2)
    {
        if(a[i]+m>a[1]&&a[i+1]+m>a[1]&&a[i]+a[i+1]+m>2*a[1]) ans2+=2;
        else if(a[i]+m>a[1]||a[i+1]+m>a[1]) ans2+=1;
    }

    cout<<ans1<<" "<<ans2<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}