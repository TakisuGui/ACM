#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=1e6+10;

vector<ll> a(N);

ll f(ll x,ll y)
{
    return 2*(x&y);
}

void solve()
{
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];

    while(q--)
    {
        int l,r; cin>>l>>r;
        ll result=a[l];
        for(int i=l+1;i<=r;i++) result=f(result,a[i]);

        cout<<result<<endl;
    }
}

int main()
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