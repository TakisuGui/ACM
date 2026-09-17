#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e18;
const int MOD=1e7+7;

ll qpow(ll a,ll b)
{ 
    ll ans=1;
    while(b)
    {
        if(b&1) 
        {
            if(ans>N/a) return N+1;
            ans=(ans*a);
        }
        b>>=1;
        if(a>N/a&&b)
        {
            return N+1;
        }
        a*=a;
    }
    return ans;
}

void solve()
{
    int x,y; cin>>x>>y;

    if(x<=1)
    {
        cout<<-1<<endl;
        return;
    }

    if(x>y)
    {
        if(y==0) cout<<-1<<endl;
        else cout<<0<<endl;
        return;
    }

    if(x==y)
    {
        cout<<1<<endl;
        return;
    }
    
    int l=1,r=61,ans=-1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(qpow(x,mid)<=y)
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans<<endl;
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