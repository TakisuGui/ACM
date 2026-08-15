#include <bits/stdc++.h>
using namespace std;

int countGoodSubstrings(string s) {
    int n = s.size();
    int ans = 0;
    
    // 枚举每个位置作为子串的结尾
    for (int r = 0; r < n; r++) {
        int val = 0;          // 当前子串的值
        int one_positions = 0; // 已经看了几个 1
        
        // 从 r 往前扩展
        for (int l = r; l >= 0; l--) {
            if (s[l] == '1') {
                one_positions++;
                // 如果已经超过18个1，就不用再看了
                if (one_positions > 18) break;
                
                // 计算这个 1 的权重
                int weight = 1 << (r - l);
                val += weight;
            }
            // 如果 s[l] == '0'，val 不变
            
            int len = r - l + 1;  // 子串长度
            
            // 如果值等于长度，找到一个好子串
            if (val == len) {
                ans++;
            }
            
            // 如果值已经大于 n，不可能再等于长度了（因为长度 ≤ n）
            if (val > n) break;
        }
    }
    
    return ans;
}

int main() {
    string s = "1011";
    cout << countGoodSubstrings(s) << endl;  // 输出 5
    return 0;
}