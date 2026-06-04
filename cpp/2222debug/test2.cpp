#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e3+10;

// 成员函数做友元
class build2;
class f11
{
public:
    f11();

    void vis2();

    build2* building;
};
class build2
{
    friend void f11::vis2();
public:
    build2(); // 类內声明 类外实现

    string m_room;
private:
    string m_bed;
};
build2::build2()
{
    m_bed="123";
    m_room="456";
}
f11::f11()
{
    building=new build2;
}
void f11::vis2()
{
    cout<<building->m_room<<" "<<building->m_bed<<endl;
}
void test12()
{
    f11 p;
    p.vis2();
}


signed main()
{
    test12();

    return 0;
}