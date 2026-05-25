#include <iostream>
using namespace std;

// 逻辑运算函数
bool NOT(bool x) { return !x; }
bool AND(bool x, bool y) { return x && y; }
bool OR(bool x, bool y) { return x || y; }
bool IMPLY(bool x, bool y) { return !x || y; }
bool EQUIV(bool x, bool y) { return x == y; }

int main() {
    int p, q;
    
    cout << "========== 逻辑联结词真值计算器 ==========" << endl;
    cout << "请输入命题P的真值(0=假,1=真):";
    cin >> p;
    cout << "请输入命题Q的真值(0=假,1=真):";
    cin >> q;
    
    // 转换为布尔值
    bool P = (p == 1);
    bool Q = (q == 1);
    
    cout << "\n========== 计算结果 ==========" << endl;
    cout << "P = " << p << ", Q = " << q << "\n" << endl;
    cout << "┌─────────────┬──────────┬─────┐" << endl;
    cout << "│ 联结词      │ 表达式   │ 结果│" << endl;
    cout << "├─────────────┼──────────┼─────┤" << endl;
    cout << "│ 否定        │ ~P       │  " << NOT(P) << "  │" << endl;
    cout << "│ 否定        │ ~Q       │  " << NOT(Q) << "  │" << endl;
    cout << "│ 合取        │ P ∧ Q    │  " << AND(P, Q) << "  │" << endl;
    cout << "│ 析取        │ P ∨ Q    │  " << OR(P, Q) << "  │" << endl;
    cout << "│ 蕴含        │ P → Q    │  " << IMPLY(P, Q) << "  │" << endl;
    cout << "│ 等价        │ P ? Q    │  " << EQUIV(P, Q) << "  │" << endl;
    cout << "└─────────────┴──────────┴─────┘" << endl;
    
    return 0;
}