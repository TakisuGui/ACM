#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

// next_p[位置][字符]
// S 长度 2e5, 字符 26 个
int next_p[200005][26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S, T;
    cin >> S >> T;

    int n = S.length();
    int m = T.length();

    // 1. 预处理序列自动机 (从后往前)
    // 初始化：如果找不到，统一设为 n+1 (越界标志)
    for (int c = 0; c < 26; c++) next_p[n + 1][c] = n + 1;
    for (int c = 0; c < 26; c++) next_p[n + 2][c] = n + 1;

    for (int i = n; i >= 1; i--) {
        // 先继承后一位的状态
        for (int c = 0; c < 26; c++) {
            next_p[i][c] = next_p[i + 1][c];
        }
        // 更新当前位字符的位置 (注意 S 下标从 0 开始，这里 i 从 1 开始)
        next_p[i][S[i - 1] - 'a'] = i;
    }

    ll total_subsegments = (ll)n * (n + 1) / 2;
    ll contains_T_count = 0;

    // 2. 遍历左端点 L
    for (int L = 1; L <= n; L++) {
        int cur = L;
        bool possible = true;

        // 在 S 中按顺序跳跃寻找 T 的字符
        for (int j = 0; j < m; j++) {
            if (cur > n) { 
                possible = false; 
                break; 
            }
            // 找到字符 T[j] 第一次出现的位置
            int target_char = T[j] - 'a';
            cur = next_p[cur][target_char];
            
            if (cur > n) { 
                possible = false; 
                break; 
            }
            // 找到了，找下一个字符时要从 cur+1 开始
            if (j < m - 1) cur++; 
        }

        if (possible) {
            // cur 就是最小的结束位置 R
            contains_T_count += (n - cur + 1);
        }
    }

    // 3. 最终答案 = 总数 - 包含 T 的
    cout << total_subsegments - contains_T_count << endl;

    return 0;
}