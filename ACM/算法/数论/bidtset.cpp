#include <bitset>
#include <iostream>
using namespace std;

bitset<8> bs1;              // 00000000，大小8位
bitset<8> bs2(42);          // 00101010，用整数初始化
bitset<8> bs3("1100");      // 00001100，用字符串初始化（从右向左读）

int main()
{
// 访问和修改
bs1[0] = 1;                 // 设置第0位为1：00000001
bs1.set(1);                 // 设置第1位为1：00000011
bs1.reset(0);               // 重置第0位为0：00000010
bs1.flip();                 // 全部翻转：11111101

// 常用操作
cout << bs1.count();        // 统计1的个数
cout << bs1.any();          // 是否有1
cout << bs1.none();         // 是否全0
cout << bs1.test(2);        // 测试第2位是否为1

// 位运算
bitset<8> a("1010");
bitset<8> b("1100");
auto c = a & b;             // 1000（与）
auto d = a | b;             // 1110（或）
auto e = a ^ b;             // 0110（异或）
auto f = ~a;                // 0101（取反）

}