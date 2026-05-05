#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x,y;

int main()
{
    cin>>x>>y;

    ll a=x,b=y;

    ll ans=0;

    while(a&&b)
    {
        ll temp_a=a,temp_b=b;

        a=max(temp_a,temp_b);
        b=min(temp_a,temp_b);

        ans+=(a/b)*4*b;
        a=a%b;
    }

    cout<<ans<<endl;

    return 0;
}