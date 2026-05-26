#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;

ll count_at_least(int n,int k,vector<ll>& cnt2,vector<ll>& cnt5)
{
    if(k==0) return(ll)n*(n+1)/2;
    ll res=0; int l=1; ll s2=0,s5=0;

    for(int r=1;r<=n;r++)
    {
        s2+=cnt2[r];
        s5+=cnt5[r];

        while(l<=r&&min(s2,s5)>=k)
        {
            res+=(n-r+1);

            s2-=cnt2[l];
            s5-=cnt5[l];
            l++;
        }
    }

    return res;
}

void solve()
{
    int n,k; cin>>n>>k;
    vector<ll> cnt2(n+1),cnt5(n+1);
    for(int i=1;i<=n;i++)
    {
        ll x; cin>>x;
        while(x%2==0) {cnt2[i]++;x/=2;}
        while(x%5==0) {cnt5[i]++;x/=5;}
    }

    ll ans = count_at_least(n,k,cnt2,cnt5) - count_at_least(n,k+1,cnt2,cnt5);
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}


            