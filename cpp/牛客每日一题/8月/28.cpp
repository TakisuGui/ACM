#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
const int N=1e18;
const int MOD=998244353;

void solve()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n == 1)
    {
        cout << a[1] << endl;
        return;
    }
    int diff = max(1, n - 1 - k);

    int maxi = 0;
    int res = 0;

    // 右端点 i 从 1 + diff 开始（确保左端点 i - diff >= 1）
    for (int i = 1 + diff; i <= n; i++)
    {
        // 维护合法左端点 1 到 i - diff 范围内的最大值
        maxi = max(maxi, a[i - diff]);

        // 更新答案
        res = max(res, maxi + a[i]);
    }

    cout << res << endl;
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