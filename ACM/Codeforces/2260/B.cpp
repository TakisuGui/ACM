#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=998244353;


void solve()
{
    int x,y,k; cin>>x>>y>>k;
    int d=y-x;
    int total=0;
    int has_months=0;

    while(has_months<k&&(x+has_months)<=d)
    {
        total+=d%(x+has_months);
        has_months++;
    }

    if(has_months<k)
    {
        ll remain_month=k-has_months;
        total+=remain_month*d;
    }
    cout<<total<<endl;
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