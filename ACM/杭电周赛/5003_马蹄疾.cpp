#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=15;

void solve()
{
    ll n,t,s; cin>>n>>t>>s;

    ll top=((1ll<<t)-1)*n;

    if(s>=0&&s<=top) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T;
    while(T--)
    {
        solve();
    }

    return 0;
}