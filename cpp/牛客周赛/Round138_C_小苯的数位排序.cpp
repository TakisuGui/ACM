#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;

ll a[N];

ll digit_sum(ll n)
{
    ll cnt=0;
    while(n>0)
    {
        cnt+=n%10;
        n/=10;
    }

    return cnt;
}

void solve()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    int ans=0;
    for(int i=n-1;i>=1;i--)
    {
        while(a[i]>a[i+1])
        {
            if(a[i]==digit_sum(a[i]))
            {
                cout<<"-1"<<endl;
                return;
            }

            a[i]=digit_sum(a[i]);
            ans++;
        }
    }

    cout<<ans<<endl;
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