#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


// 加法运算符重载
class f12
{
public:

    // 成员函数重载加号
    // f12 operator+(f12 p)
    // {
    //     f12 p3;
    //     p3.m_a=this->m_a+p.m_a;
    //     p3.m_b=this->m_b+p.m_b;
    //     return p3;
    // }

    int m_a;
    int m_b;
};
// 全局函数重载加号
f12 operator+(f12 p1,f12 p2)
{
    f12 p3;
    p3.m_a=p1.m_a+p2.m_a;
    p3.m_b=p1.m_b+p2.m_b;
    return p3;
}
void test13()
{
    f12 p1;
    p1.m_a=10,p1.m_b=20;
    f12 p2;
    p2.m_a=30,p2.m_b=40;

    f12 p3=p1+p2;
    // 成员函数本质调用  p3 = p1.operator+(p2);
    // 全局函数本质调用  p3 = operator(p1,p2);
    cout<<p3.m_a<<" "<<p3.m_b<<endl;
}


// 左移运算符重载  
// 一般不会在成员函数內重载 << 运算符  因为无法实现 cout 在左侧
class f13
{
    friend ostream& operator<<(ostream& cout,f13 p);
public:
    f13(int a,int b): m_a(a),m_b(b){};
private:

    int m_a;
    int m_b;
};
ostream& operator<<(ostream& cout,f13 p) // ostream 类没有拷贝构造函数,所以必须传引用
{
    cout<<p.m_a<<" "<<p.m_b;
    return cout;
}
void test14()
{
    f13 p1(10,20);
    cout<<p1<<endl;
}


// 递增运算符重载
class f14
{
    friend ostream& operator<<(ostream& cout,f14 p);
public:
    f14()
    {
        m_num=0;
    }

    // 重载前置递增运算符
    f14& operator++()
    {
        m_num++;
        return *this;
    }
    // 重载后置递增运算符
    f14 operator++(int) //int 这里是占位参数
    {
        f14 temp=*this;
        m_num++;
        return temp;
    }

private:
    int m_num;
};
ostream& operator<<(ostream& cout,f14 p)
{
    cout<<p.m_num;
    return cout;
}
void test15()
{
    f14 p;
    cout<<++p<<endl;
    cout<<p++<<endl;
    cout<<p<<endl;
}


// 赋值运算符重载
class f15
{
public:
    f15(int age)
    {
        m_age=new int(age);
    }

    f15& operator=(f15& p)
    {
        if(m_age!=NULL)
        {
            delete m_age;
            m_age=NULL;
        }

        m_age=new int(*p.m_age);
        return *this;
    }

    ~f15()
    {
        if(m_age!=NULL)
        {
            delete m_age;
            m_age=NULL;
        }
    }

    int *m_age;
};
void test16()
{
    f15 p1(18);
    f15 p2(20);
    f15 p3(0);
    cout<<*p1.m_age<<endl;
    p3=p2=p1;
    cout<<*p2.m_age<<" "<<*p3.m_age<<endl;
}


// 关系运算符重载
class f16
{
public:
    f16(string name,int age): m_name(name),m_age(age){};

    bool operator==(f16& p)
    {
        if(this->m_age==p.m_age&&this->m_name==p.m_name)
        {
            return true;
        }
        return false;
    }

    string m_name;
    int m_age;
};
void test17()
{
    f16 p1("abc",114514);
    f16 p2("abc",114514);
    f16 p3("xyz",114514);
    cout<<(p1==p2 ? "Yes" : "No")<<endl;
    cout<<(p3==p2 ? "Yes" : "No")<<endl;
}

// 函数调用重载
// 重载后也称 仿函数
class f17
{
public:
    void operator()(string test)
    {
        cout<<test;
    }
    int operator()(int a,int b)
    {
        return a+b;
    }

};
void test18()
{
    f17 p;
    p("hello world\n");
    cout<<p(10,20)<<endl;
    cout<<f17()/*匿名对象*/(114514,114514)<<endl;
}