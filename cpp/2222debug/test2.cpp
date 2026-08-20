#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 优化输入输出速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long M;
    if (!(cin >> N >> M)) return 0;

    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    // 1. 计算 Ayu 能解出几道题，以及拿到每个气球的具体时间
    int K = 0;
    long long time_ayu = 0;
    vector<long long> T; // 记录 Ayu 拿到气球的时间点
    for (int i = 0; i < N; ++i) {
        time_ayu += A[i];
        if (time_ayu <= M) {
            K++;
            T.push_back(time_ayu);
        } else {
            break;
        }
    }

    // 如果 Ayu 一题都解不出，必败
    if (K == 0) {
        cout << -1 << "\n";
        return 0;
    }

    // 2. 标记 Budi 的前 K 个任务中，哪些是“后缀最大值”
    vector<bool> is_suf_max(K, false);
    long long cur_max = -1;
    for (int j = K - 1; j >= 0; --j) {
        if (B[j] >= cur_max) {
            is_suf_max[j] = true;
            cur_max = B[j];
        }
    }

    // 3. 模拟 Budi 的做题过程
    int ayu_idx = 0; // Ayu 当前可用的下一个气球索引
    long long budi_time = 0; // Budi 当前消耗的总时间
    vector<long long> pops; // 记录扎气球的时间

    for (int j = 0; j < K; ++j) {
        long long t_finish = budi_time + B[j];
        
        // 如果 Budi 即使没有气球干扰，完成这题也已经超时了，Ayu 直接赢
        if (t_finish > M) {
            break;
        }

        // 如果这是一个“后缀最大值”任务，疯狂砸手里可用的气球
        if (is_suf_max[j]) {
            // 条件：Ayu 还有气球，且下一个气球的获取时间 <= Budi 原本将要完成这题的时间
            while (ayu_idx < K && T[ayu_idx] <= budi_time + B[j]) {
                long long pop_time = budi_time + B[j];
                pops.push_back(pop_time);
                budi_time += B[j]; // Budi 的进度被重置，时间硬生生增加了 B[j]
                ayu_idx++;

                // 如果砸完这次气球后，Budi 下一次尝试完成的时间已经超过了 M，Ayu 直接赢
                if (budi_time + B[j] > M) {
                    goto WIN; // 跳出多重循环的快捷方式
                }
            }
        }
        
        // 不管有没有被砸气球，最终 Budi 做完了这题（或者准备做下一题），基础时间推进
        budi_time += B[j];
    }

    // 如果顺利走出了上面的循环，说明 Budi 在 M 分钟内完成了前 K 题，Ayu 没能阻止他
    cout << -1 << "\n";
    return 0;

WIN:
    // Ayu 获胜，输出需要扎破的气球数和扎破的时间列表
    cout << pops.size() << "\n";
    if (!pops.empty()) {
        for (int i = 0; i < pops.size(); ++i) {
            cout << pops[i] << (i == pops.size() - 1 ? "" : " ");
        }
        cout << "\n";
    } else {
        cout << "\n";
    }

    return 0;
}