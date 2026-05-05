#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+10;

ll pref_r[N], pref_y[N], pref_w[N];

ll value(ll l,ll r,ll m)
{
    ll nr=pref_r[r]-pref_r[l-1];
    ll ny=pref_y[r]-pref_y[l-1];
    ll nw=pref_w[r]-pref_w[l-1];

    ll v1=2*nr+ny;
    ll v2=nr+2*ny;

    ll max_v=max(v1,v2);

    ll pint=min(m,nw);
    ll ex_v=pint*2;

    return ex_v+max_v;
}

int main()
{
    int T;cin>>T;

    while(T--)
    {
        ll n,m;ll k;
        cin>>n>>m>>k;

        string s;cin>>s; s=' '+s;

        for(int i=1;i<=n;i++)
        {
            pref_r[i] = pref_r[i-1] + (s[i] == 'r');
            pref_y[i] = pref_y[i-1] + (s[i] == 'y');
            pref_w[i] = pref_w[i-1] + (s[i] == 'w');
        }

        ll ans=n+1;
        ll l=1;

        for(int r=1;r<=n;r++)
        {
            while(l<=r&&value(l,r,m)>=k)
            {
                ans=min(ans,r-l+1);
                l++;
            }
        }

        if (ans > n) cout << -1 << endl;
        else cout << ans <<endl;

    }
    return 0;
}