#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 一共有n颗石子,两个人轮流拿,每次可以拿1~m颗石子
    string bashGame_SG(int n, int m) 
    {
		vector<int> sg(n,0);
        
        for(int i=1;i<=n;i++)
        {
            vector<bool> appear(m+1,false);
            for(int j=1;j<=m&&i-j>0;j++)
            {
                appear[sg[i-j]]=true; 
                // 找从 i-1 到 i-m 的前驱
                // 把这些前驱出现过的值标记
            }

            for(int k=0;k<=m;k++)
            {
                if(!appear[k]) {sg[i]=k; break;}
            }
        }

        return sg[n]!=0 ?  "先手" : "后手";
	}
};


// sg函数 如果等于零代表现在这个状态的人(先手)必输
// sg的值由前驱的所有sg值所组成数组 中未出现的最小自然数

// 前驱指 在这个博弈中 现在的情况可以去往哪些情况
// 比如在这个bash博弈中,现在 有t个石子,那么可以通过拿 1~m个
// 从而去往 t-m ~ t-1 的所有情况 (当然上述应该大于零)
// 这也是为什么这个题的sg值不大于m

// sg定理 若一个公平组合游戏(ICG) 由多个ICG组成 那么
//        这个sg(总) ^= sg(i); (即所有小游戏的sg异或和)
// 其由尼姆博弈易证
