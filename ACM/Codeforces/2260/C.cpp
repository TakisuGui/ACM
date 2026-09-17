#include <iostream>
using namespace std;
typedef long long ll;

void solve() {
    ll x, y;
    cin>>x>>y;
    ll sum=x+y;

    ll tar_x = 0;
    for (int b = 60; b >= 0; b--) {
        if ((sum >> b) & 1) {
            if (tar_x + (1LL << b) <= x) {
                tar_x += (1LL << b);
            }
        }
    }

    cout << sum << " " << (x - tar_x) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}