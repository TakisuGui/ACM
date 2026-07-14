#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


// 继承 基本语法
class f18 // 父类 基类
{
public:
    void p_a() {cout<<114514<<endl;}
    void p_b() {cout<<1919810<<endl;}
};
class f19:public f18 // 子类 派生类
{

};
void test19()
{
    f18 p; f19 p2;
    p.p_a();p.p_b();
    p2.p_a();
}


// 继承方式
// 父类中的私有成员 子类无法访问
// 私有继承  父类中所有非私有成员 在子类中变为私有成员
// 公共继承  子类的类型和父类中类型完全一致
// 保护继承  父类中所有非私有成员 在子类中变为保护成员
class f20
{
public:
    int m_a;
protected:
    int m_b;
private:
    int m_c;
};
class f21:public f20
{
    void func()
    {
        m_a=10;
        m_b=20; //父类中保护成员 只有其自身和其子类可以访问 类外无法访问
        // m_c=30; 父类中私有成员 子类无法访问
    }
};


// 继承中的对象模型
class f22
{
public:
    int m_a;
    static int m_x;
protected:
    int m_b;
private:
    int m_c; 
};
class f23 :public f22
{
    int m_d;
};
int f22::m_x=114514;
void test20()
{
    f23 p;
    f22 p1;
    cout<<sizeof p1<<endl;
    cout<<sizeof p<<endl;
    cout<<f22::m_x<<endl;
    f22::m_x=1919810;
    cout<<f23::m_x<<endl;
    // 父类中非静态成员属性 都会被子类继承下去
}


// 继承中 构造和析构 顺序
// 先调用父类构造,再是子类
// 析构顺序相反
class f24
{
public:
    f24()
    {
        cout<<"父类构造函数调用"<<endl;
    }
    ~f24()
    {
        cout<<"父类析构函数调用"<<endl;
    }
    int m_a;
};
class f25: public f24
{
public:
    f25()
    {
        cout<<"子类构造函数调用"<<endl;
    }
    ~f25()
    {
        cout<<"子类析构函数调用"<<endl;
    }
};
void test21()
{
    f25 p;
}


// 继承中同名成员处理方式
// 访问子类同名 可以直接访问
// 访问父类同名 要加上作用域
class f26
{
public:
    f26()
    {
        m_a=100;
    }

    void func()
    {
        cout<<"父类成员函数调用"<<endl;
    }
    void func(int a)
    {
        cout<<"父类成员函数重载后调用"<<endl;
    }
    int m_a;

protected:
    int m_b;
private:
    int m_c; 
};
class f27: public f26
{
public:
    int m_a;
    f27()
    {
        m_a=200;
    }
    void func()
    {
        cout<<"子类成员函数调用"<<endl;
    }
    void func(int a)
    {
        cout<<"子类成员函数重载后调用"<<endl;
    }
    
};
void test22()
{
    f27 p;
    cout<<p.m_a<<endl;
    cout<<p.f26::m_a<<endl;
    p.func();
    p.f26::func();
    p.f26::func(100); // 子类和父类 如果存在 同名函数 子类同名成员会隐藏 父类中所有的同名函数
    p.func(10);
}


// 继承中 同名静态函数 处理方式
class f28
{
public:
    int m_a;
    static int m_b;
    static void func()
    {
        cout<<"父类静态成员函数调用"<<endl;
    }
};
int f28::m_b=100;
class f29: public f28
{
public:
    static int m_b;
    static void func()
    {
        cout<<"子类静态成员函数调用"<<endl;
    }
};
int f29::m_b=200;
void test23()
{
    f29 p;
    cout<<p.m_b<<endl;
    cout<<p.f28::m_b<<endl;
    cout<<f29::m_b<<endl; //通过类名访问
    cout<<f29::f28::m_b<<endl; // 第一个 :: 表示通过类名访问 第二个 :: 访问父类作用域下的 m_b
    p.func();
    p.f28::func();
    f29::func();
    f29::f28::func();
    // 子类和父类 如果存在 同名静态函数 子类同名静态成员会隐藏 父类中所有的同名静态函数
}


// 多继承语法
// 多继承可能引发 继承的多个父类 有同名成员出现 要加作用域区分
class f30
{
public:
    f30()
    {
        m_a=10;
    }
    int m_a;
};
class f31
{
public:
    f31()
    {
        m_a=20;
    }
    int m_a;
};
class f32: public f30,public f31
{
public :
    f32()
    {
        m_a=30;
    }
    int m_a;
};
void test24()
{
    f32 p;
    cout<<sizeof p<<endl;
    cout<<p.m_a<<endl;
    cout<<p.f30::m_a<<endl;
    cout<<p.f31::m_a<<endl;
}


// 菱形继承
// 俩个派生类 继承同一个 基类
// 俩个派生类 又被同一个类继承 就是 菱形继承
class f33
{
public:
    int m_a;
};
class f34:virtual public f33
{

};
class f35:virtual public f33
{

};
class f36: public f34,public f35
{

};
void test25()
{
    f36 p;
    // 菱形继承 多个父类有相同数据 要加作用域区分
    p.f35::m_a=30;
    cout<<p.m_a<<endl;
    p.f34::m_a=50;
    cout<<p.m_a<<endl;
    //虚继承后共享一份数据
}


int main()
{
    test24();

    return 0;
}