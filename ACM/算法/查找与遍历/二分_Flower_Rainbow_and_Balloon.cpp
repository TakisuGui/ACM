#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+10;

ll pref_r[N], pref_y[N], pref_w[N];
ll n,m;ll k;


ll value(ll l,ll r,ll p)
{
    ll nr=pref_r[r]-pref_r[l-1];
    ll ny=pref_y[r]-pref_y[l-1];
    ll nw=pref_w[r]-pref_w[l-1];

    ll v1=2*nr+ny;
    ll v2=nr+2*ny;

    ll max_v=max(v1,v2);

    ll pint=min(p,nw);
    ll ex_v=pint*2;

    return ex_v+max_v;
}


bool check(ll len)
{
    if(len==0) return false;

    for(ll i=1;i+len-1<=n;i++)
    {
        int r=i+len-1;
        if(value(i,r,m)>=k) return true;

    }
    return false;
}
int main()
{
    int T;cin>>T;

    while(T--)
    {
        cin>>n>>m>>k;

        string s;cin>>s; s=' '+s;

        for(int i=1;i<=n;i++)
        {
            pref_r[i] = pref_r[i-1] + (s[i] == 'r');
            pref_y[i] = pref_y[i-1] + (s[i] == 'y');
            pref_w[i] = pref_w[i-1] + (s[i] == 'w');
        }

        ll left = 1, right = n, ans = n+1;

        while(left<=right)
        {
            ll mid=(left+right)/2;

        if(check(mid))
        {
            ans=mid;
            right=mid-1;
        }
        else left=mid+1;
        }

        if (ans == n + 1) cout << -1 << endl;  
        else cout << ans << endl;
    }
    
}


//lower_bound(begin, end, x)	第一个 >= x 的位置
//upper_bound(begin, end, x)	第一个 > x 的位置
//binary_search(begin, end, x)	判断 x 是否存在