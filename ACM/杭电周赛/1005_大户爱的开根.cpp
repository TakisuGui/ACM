#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll qpow(ll x,ll p,ll lim)
{
    ll ans=1;
    for(int i=0;i<p;i++)
    {
        if(ans>lim/x) return lim+1;
        ans*=x;
    }
    return ans;
}


void slove()
{
    ll n,k; cin>>n>>k;
    if(k==1)
    {
        cout<<n<<"\n";
        return;
    }
    if(k>60)
    {
        cout<<"1\n";
        return;
    }
    ll low=1,high=sqrt(n)+5;

    while(low<=high)
    {
        ll mid=(low+high)/2;
        ll val=qpow(mid,k,n);
        if(val>n) high=mid-1;
        else low=mid+1;
    }

    cout<<high<<"\n";
    return;
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