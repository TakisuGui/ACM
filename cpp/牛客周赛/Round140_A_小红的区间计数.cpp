#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll a,b,c,l,r; cin>>a>>b>>c>>l>>r;

    ll ans=r-l+1;

    if(a>=l&&a<=r) ans--;
    if(b>=l&&b<=r&&a!=b) ans--;
    if(c>=l&&c<=r&&a!=c&&b!=c) ans--;

    cout<<ans<<endl;

    return 0;
}