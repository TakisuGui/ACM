#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=2e5+10;

void solve()
{
    ll x,y; cin>>x>>y;

    int u=32-__builtin_clz(y);

    cout<<((1u<<u)-1)<<endl;
    
}


int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}