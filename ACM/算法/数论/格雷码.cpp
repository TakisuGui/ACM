#include<bits/stdc++.h>
using namespace std;

// 任意两个相邻的数值，对应的二进制表示中只有“一位”（1 个 bit）不同。


vector<int> grayCode(int n) 
{
    vector<int>res;
    for (int i=0; i<(1<<n);i++) {
        res.push_back(i^(i>>1));
    }
    return res;
}