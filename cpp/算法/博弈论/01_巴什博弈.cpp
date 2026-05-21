#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 一共有n颗石子,两个人轮流拿,每次可以拿1~m颗石子
    string bashGame(int n, int m) 
    {
		return n%(m+1) != 0 ? "先手" : "后手";
	}
};


// 若一开始 n 不是 (m+1)的倍数 先手可以把它变成 n 的倍数再交给后手
// 这样后手只能再把 n 变成不是 (m+1)的倍数
// 到最后 后手一定会首先面对 n==m+1
// 所以先手必赢

// 反之, 一开始 n 是 (m+1)的倍数
// 轮到后手时,n 一定不是 (m+1)的倍数,所以后手必赢
