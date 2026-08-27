#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    int m = n - k;

    if (m <= 1) {
        for (int i = 1; i <= k; ++i) {
            cout << i << (i == k ? "" : " ");
        }
        cout << "\n";
        return 0;
    }

    vector<int> keep; 
    int best_step = -1;
    for (int step = 1; step < n; ++step) {
        if (__gcd(step, n) == 1) {
            best_step = step;
            break;
        }
    }

    if (best_step != -1 && (m - 1) * best_step < n) {

        for (int i = 0; i < m; ++i) {
            keep.push_back(1 + i * best_step);
        }
    } else {
        
        for (int i = 1; i <= m; ++i) {
            keep.push_back(i);
        }
    }

    vector<bool> is_kept(n + 1, false);
    for (int x : keep) {
        is_kept[x] = true;
    }

    bool first = true;
    for (int i = 1; i <= n; ++i) {
        if (!is_kept[i]) {
            if (!first) cout << " ";
            cout << i;
            first = false;
        }
    }
    cout << "\n";

    return 0;
}