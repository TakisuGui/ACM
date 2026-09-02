#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e18;
const int MOD=998244353;

ll lowbit(ll x){
    return x&-x;
}

void solve()
{
    int a; cin>>a;
    int b,c;
    if (a==1) 
    {
        b=2;
        c=3;
    } 
    else if(a==(1e9))
    {
        ll x=a^lowbit(a);
        b=x; c=b^a;
        
    }
    else 
    {
        b=1;
        c=1^a;
    }
    cout<<b <<" "<<c<<endl;
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