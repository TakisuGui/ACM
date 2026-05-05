#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void slove()
{
    ll n,m;; cin>>n>>m;
    ll ans=0;
    ll tmp=n;

    for(int i=32;i>=0;i--)
    {
        ll try_val=(1ll<<i);
        if(m*try_val<=tmp)
        {
            tmp-=m*try_val;
            ans|=try_val;
        }
        else if(tmp>try_val*m-m)

        {
             tmp-=(tmp-try_val*m+m+try_val-1)/try_val*try_val;
        }
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--)
    {
        slove();
    }

    return 0;
}