#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e9+7;

void f(ll n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            cout<<i<<" ";
            while(n%i==0) n/=i;
        }
    }

    if(n>1) cout<<n;
    cout<<endl;
}

void solve()
{
   int n; cin>>n;
   f(n);
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