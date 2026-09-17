#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll


void solve()
{
    int n; cin>>n;

    set<long long> st;

    for (int i=0;i<n;i++) 
    {
        long long x; cin>>x;
        st.insert(x);
    }

    cout<<(st.size()<= 3?"YES":"NO")<<endl;
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