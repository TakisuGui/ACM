#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


// 函数模板
template<typename T>
void myswap(T& a,T& b)
{
    T temp=a;
    a=b;
    b=temp;
}
void test34()
{
    // 自动类型推导
    int a=10,b=20;
    myswap(a,b);
    cout<<a<<" "<<b<<endl;

    // 显示指定类型
    myswap<int>(a,b);
    cout<<a<<" "<<b<<endl;

}

// 函数模板注意事项
// 自动类型推导 必须推导出一致的数据类型才可以使用
// 模板必须先确定 T 的数据类型 才可以使用

template<class T1>
void func()
{
    cout<<114514<<endl;
}
void test35()
{
    int a=10; char c='a';
    // myswap(a,c);  数据类型 不一致 无法使用

    // func();   没有 先确定 T 的数据类型
    func<int>();
}

 
 // 普通函数 和 函数模板区别
 // 普通函数可发生隐式类型转换
 // 函数模板 用自动类型推导 不能隐式类型转换
 // 函数模板 用显示指定类型 可以隐式类型转换
int myadd01(int a,int b){ return a+b;}
template<class T2>
int myadd02(T2 a,T2 b){ return a+b;}
void test36()
{
    int a=10,b=20;
    cout<<myadd01(a,b)<<endl;
    char c='c';
    cout<<myadd01(a,c)<<endl;

    cout<<myadd01(a,b)<<endl;
    // cout<<myadd01(a,c)<<endl;

    cout<<myadd02<int>(a,c)<<endl;
}


// 普通函数 和 函数模板 调用规则
// 如果二者 都可以实现 优先调用 普通函数
// 可以通过 空模板参数列表 强制调用函数模板
// 函数模板 也可以 重载
// 如果函数模板 有更好的匹配 优先调用函数模板
void myprint(int a,int b){ cout<<"调用普通函数"<<endl;}
template<class T3>
void myprint(T3 a,T3 b){ cout<<"调用函数模板"<<endl;}
template<class T3>
void myprint(T3 a,T3 b,T3 c){ cout<<"调用重载的函数模板"<<endl;} // 发生重载
void test37()
{
    int a=10,b=20;
    myprint(10,20);   //调用普通函数
    // 普通函数不能为空 否则会报错

    //通过空模板参数列表 强制调用函数模板
    myprint<>(a,b);

    //函数模板也可以重载
    myprint<>(a,b,a);

    //如果函数模板 有更好的匹配 优先调用函数模板
    char c1='a',c2='b';
    myprint(c1,c2);
}


// 模板局限性
// 特定的数据类型 需要具体化方式实现
class f45
{
public:
    f45(string s,int a): name(s),m_age(a){};

    string name;
    int m_age;
};
template<class T4>
bool mycompare(T4& a,T4& b)
{
    return(a==b ? true : false);
}
// 利用具体化 f45 版本实现 具体化会优先调用
template<> bool mycompare(f45& p1,f45& p2)
{
    if(p1.m_age==p2.m_age&&p1.name==p2.name) return true;
    else return false;
}
void test38()
{
    int a=10,b=20;
    cout<<(mycompare(a,b) ? "true" : "false")<<endl;

    f45 p1("TOM",10),p2("TOM",10);
    cout<<(mycompare(p1,p2) ? "true" : "false")<<endl;
}


// 类模板
template <class nametype,class agetype>
class f46
{
public:
    f46(nametype s,agetype a): name(s),m_age(a){};
    void show()
    {
        cout<<this->m_age<<" "<<this->name<<endl;
    }

    nametype name;
    agetype m_age;
};
void test39()
{
    f46<string,int> p1("Tom",18);
    p1.show();
}


// 类模板 和 函数模板 区别
// 类模板 没有 自动类型推导
// 类模板 在模板参数列表中 可以有默认参数 
template <class nametype,class agetype = int /*默认参数*/>
class f47
{
public:
    f47(nametype s,agetype a): name(s),m_age(a){};
    void show()
    {
        cout<<this->m_age<<" "<<this->name<<endl;
    }

    nametype name;
    agetype m_age;
};
void test40()
{
    // f47 p("sum",10);  类模板没有自动类型推导  cpp17 之后
    f47<string ,int> p("sum",18);
    p.show();
    f47<string> p2("Tom",24);
    p2.show();
}


// 类模板 成员函数创建时机
// 普通类成员函数 编译时创建
// 模板类成员函数 调用时创建
class f48
{
public:
    void show1()
    {
        cout<<114514<<endl;
    }
};
class f49
{
public:
    void show2()
    {
        cout<<1919810<<endl;
    }
};
template <class T>
class f50
{
public:
    void func1()
    {
        a.show1();
    }
    void func2()
    {
        a.show2();
    }
    T a;    
};
void test41()
{
    // 一开始没调用 类模板 所以不明确 类中参数类型 故而可以通过编译(没有编译 f50)

    f50<f48> p1;
    p1.func1();
    f50<f49> p2;
    p2.func2();

    // 指定类模板的参数类型后 调用模板类成员函数 如果 这个参数类型所属的类中 有该成员函数 就可以调用
}


// 类模板对象 做函数参数
// 1.指定参数类型
// 2.参数模板化
// 3.整个类模板化
template <class T1,class T2>
class f51
{
public:
    f51(T1 s,T2 a): name(s),m_age(a){};
    void show()
    {
        cout<<this->m_age<<" "<<this->name<<endl;
    }

    T1 name;
    T2 m_age;
};
// 指定参数传入类型
void print0(f51<string,int>& p)
{
    p.show();
}
// 参数模板化
template <class T1,class T2>
void print1(f51<T1,T2>& p)
{
    p.show();
    cout<<typeid(T1).name()<<"  "<<typeid(T2).name()<<endl; // 查看参数类型
}
template <class T>
void print3(T& p)
{
    p.show();
    cout<<typeid(T).name()<<endl;
}
void test42()
{
    f51<string,int> p1("Tom",18);
    print0(p1);

    f51<string,int> p2("Sum",24);
    print1(p2);

    f51<string,int> p3("homo",1919810);
    print3(p3);
}


// 类模板 与 继承
// 子类继承的父类 是类模板时 子类在声明的时候 必须指定父类中 T 的类型
// 不指定 编译器不给子类分配内存  因为不知道类型 就不知道需要分配内存的大小
// 如果想灵活指定父类中 T 的类型 子类也需要变成类模板
template <class T>
class f52
{
public:
    T a;
};
class f53: public f52<int>
{
};
template <class T1,class T2>
class f54: public f52<T1>
{
public:
    f54()
    {
        cout<<typeid(T1).name()<<endl;
        cout<<typeid(T2).name()<<endl;
    }
    T2 b;
};
void test43()
{
    f53 p1;
    f54<int,char> p2;
}


// 类模板成员函数 类外实现
template <class T1,class T2>
class f55
{
public:
    f55(T1 s,T2 a);
    void show();

    T1 name;
    T2 m_age;
};
// 构造函数类外实现
template <class T1,class T2>
f55<T1,T2>::f55(T1 s,T2 a): name(s),m_age(a){};
// 成员函数类外实现
template <class T1,class T2>
void f55<T1,T2>:: show()
{
    cout<<this->m_age<<" "<<this->name<<endl;
}
void test44()
{
    f55<string,int> p("Tom",21);
    p.show();
}


// 类模板 分文件编写
// 类模板成员函数创建时机是调用阶段 所以可能导致 文件编写链接不到
// 1. 直接包含 源文件
// 2. 将 .h 和 .cpp 写到一起,然后把 .h 后缀改为 .hpp


// 类模板 和 友元
template <class T1,class T2>
class f56
{
    // 全局函数类內实现
    friend void show(f56<T1,T2>& p)
    {
        cout<<p.name<<" "<<p.m_age<<endl;
    }

public:
    f56(T1 s,T2 a): name(s),m_age(a){};

private:
    T1 name;
    T2 m_age;
};
// 全局函数类外实现
template <class T1,class T2>
class f57;
template <class T1,class T2>
void show2(f57<T1,T2>& p)
{
    cout<<p.name<<" "<<p.m_age<<endl;
}
template <class T1,class T2>
class f57
{
    friend void show2<>(f57<T1,T2>& p);

public:
    f57(T1 s,T2 a): name(s),m_age(a){};

private:
    T1 name;
    T2 m_age;
};
void test45()
{
    f56<string,int> p1("Tom",27);
    show(p1);

    f57<string,int> p2("Sum",114514);
    show2(p2);
}