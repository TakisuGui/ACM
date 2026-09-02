#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e7+7;

void solve()
{
    int n; cin>>n;
    int max_,min_;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        max_=max(max_,x),min_=min(min_,x);
    }

    if(n==1)
    {
        cout<<0<<" "<<max_<<endl;
        return;
    }

    int d=max_-min_;
    if(d%2==0)
    {
        int m=d/2;
        int x=max_-m;
        cout<<d<<" "<<x<<endl;
    }
    else
    {
        int m=(d+1)/2;
        int x=min_+m;
        cout<<d<<" "<<x<<endl;
    }
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}