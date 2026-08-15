#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
const int N=2e5;
const int MOD=1e7+7;

void solve()
{
    int n; cin >> n;

    set<ll> cookies;
    for (int i = 0; i < n; i++) 
    {
        ll a; cin >> a;
        cookies.insert(a);
    }

    ll cur_pos = 0;
    ll ans = 0;

    while (!cookies.empty())
    {
        auto it = cookies.lower_bound(cur_pos);

        ll target;
        if (it == cookies.end()) 
        {
            target = *prev(it);
        }
        else if (it == cookies.begin()) 
        {
            target = *it;
        }
        else 
        {
            ll right_val = *it;
            ll left_val = *prev(it);

            ll dis_l = abs(cur_pos - left_val);
            ll dis_r = abs(cur_pos - right_val);

            if (dis_l <= dis_r) 
            {
                target = left_val;
            } 
            else 
            {
                target = right_val;
            }
        }

        ans += abs(cur_pos - target);
        cur_pos = target;
        cookies.erase(target);
    }

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}