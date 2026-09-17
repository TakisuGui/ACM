#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int a[20];//-1 未计算, 0 必败, 1 必胜
int dp[1 << 20];

int get_dp(int mask, int n) {
    if (mask == 0) return 0; // 空集是必败态
    if (dp[mask] != -1) return dp[mask];

    // 计算当前状态下所有元素的异或和及元素数量
    int total_xor = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if ((mask >> i) & 1) {
            total_xor ^= a[i];
            count++;
        }
    }

    // 尝试删除每一个存在的元素
    for (int i = 0; i < n; i++) {
        if ((mask >> i) & 1) {
            int next_xor = total_xor ^ a[i];
            
            // 满足题目删除规则
            if (count == 1 || a[i] > next_xor) {
                // 如果能让对手进入必败态(0)，则当前必胜(1)
                if (get_dp(mask ^ (1 << i), n) == 0) {
                    return dp[mask] = 1;
                }
            }
        }
    }

    // 尝试了所有合法的移动，对手都必胜，则当前必败
    return dp[mask] = 0;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < (1 << n); i++) dp[i] = -1;

    if (get_dp((1 << n) - 1, n) == 1) cout << "Left" << endl;
    else cout << "Right" << endl;
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