#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e7+7;


void solve()
{
    int n; cin>>n;
    double min_upper_bound=1e18;
    for (int i=1; i<=n;++i) 
    {
        ll a_i; cin>>a_i;

        double current_bound=(double)(a_i + 1)/i;
        
        if (current_bound < min_upper_bound) min_upper_bound=current_bound;
    }
    cout<<fixed<<setprecision(10)<<min_upper_bound<<"\n";
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