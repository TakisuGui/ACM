#include<iostream> 
using namespace std;

// 构造函数和析构函数
class Base
{
    int x; 
public:
    Base()
    {
        cout<<"Base构造函数的调用"<<endl;
        //构造函数可以含有参数,可以重载,没有返回值
    }


    // 析构函数没有参数,不可以重载,没有返回值
    // 销毁才会调用 所以在 main 里面的时候 要按下任意键才会被执行  而如果放到全局函数里面 全局函数跑完自己就会触发调用的类的析构函数
};


// 构造函数分类
// 无参 or 有参
// 普通 or 拷贝
class f 
{
public:
    f() // 无参
    {
        cout<<"f无参构造函数的调用"<<endl;
    }

    f(int a) // 有参数
    {
        age=a;
        cout<<"f有参构造函数的调用"<<endl;
    }

    f(const f& p) // 拷贝
    {
        age=p.age;
        cout<<"f拷贝构造函数的调用"<<endl;
    }


    int age;
};

// 构造函数调用
void test()
{
    // 括号法
    f p1; //无参构造不用加() 编译器会认为是函数声明
    f p2(10);
    f p3(p2);

    cout<<p3.age<<endl<<endl;

    // 显示法
    f p4=f(10); // f(10) : 匿名对象从  当前行结束立刻回收
    f p5=f(p4);
    cout<<endl;

    // f(p4);
    // 意图：这是在 创建一个临时对象（匿名对象），并且调用 f 的构造函数，传入 p4
    // 实际上 : 编译器认为 f p4; 又创造了 p4 这个对象一次


    // 隐式法
    f p6=10; // 等价于 f p6=f(10);
    cout<<endl;
}


// 拷贝构造函数的调用时机
void dowork(f p);
void dowork2(f &p);
f dowork3();
void test01()
{
    //1. 用已经创建完毕的对象 初始化一个新对象
    f p1(20);
    f p2=f(p1); // f p2(p1);
    cout<<endl;

    //2. 以值传递方式 给 函数参数传值
    f p3;

    dowork(p3);  //  传参的时候 会创造一个新对象 调用拷贝构造函数 然后把 p3 拷贝给新对象 并且把新对象传给函数
    cout<<"0000"<<endl;
    dowork2(p3);  // 应用后 不再会创造一个新对象 所以不会调用 拷贝构造函数
    cout<<endl;

    //3. 值的方式返回 局部对象
    f p4=dowork3(); // doword3 內创造的对象和 p4 不是一个对象,是函数內创造的临时对象拷贝来的
}
void dowork(f p)
{

}
void dowork2(f &p)
{
    cout<<114514<<endl;
}
f dowork3()
{
    f p114514;
    return p114514;
}


// 构造函数调用规则
// 一个类默认 4 个函数 默认构造函数 析构函数 拷贝构造函数 赋值运算符重载
// 定义 有参构造 编译器不再提供无参 但提供拷贝
// 定义 拷贝     编译器不再提供其他构造函数


// 深拷贝和浅拷贝
// 浅拷贝: 简单赋值拷贝
// 深拷贝: 在堆区,开辟一个区域复制
class f2 
{
public:
    f2() // 无参
    {
        cout<<"f无参构造函数的调用"<<endl;
    }

    f2(int a,int high) // 有参数
    {
        m_age=a;
        m_high=new int(high);
        cout<<"f有参构造函数的调用"<<endl;
    }

    f2(const f2& p) // 改成深拷贝
    {
        cout<<"f拷贝构造函数的调用"<<endl;
        m_age=p.m_age;
        // m_high=p.m_high; 编译器默认浅拷贝,造成报错

        m_high=new int(*p.m_high); // 先解引用 拿到 high 的数值,然后重新开辟一块内存,再让类內指针指向它
    }


    ~f2()
    {   //堆区释放
        if(m_high!=NULL)
        {
            delete m_high;
            m_high=NULL;
        }
        cout<<"f析构函数的调用"<<endl;
    }

    int m_age;
    int* m_high;
};
void test02()
{
    // f2 p1(23);
    // cout<<p1.m_age<<endl;

    // f2 p2(p1); //浅拷贝
    // cout<<p2.m_age<<endl;

    int* p=new int(10); // 在堆区开辟一个 int 空间,把这个空间赋值为5,然后返回这个空间的地址,然后p指针指向这个地址
    int* arr=new int[5]; // 在堆区开辟一个长度为 5 的数组

    f2 p3(18,180);
    // 浅拷贝的匿名对象 和 p3 的high指向同一个地址(也就是p3直接拷贝了匿名对象的地址) 匿名对象用完就回收,开辟的堆区删除了,造成了p3的high地址没了(堆区内存重复释放)


}


// 初始化列表
class f3
{
public:
    f3(int a,int b,int c) : m_a(a),m_b(b),m_c(c)
    {

    }

    int m_a;
    int m_b;
    int m_c;
};
void test03()
{
    f3 p(10,20,30);
    cout<<p.m_a<<" "<<p.m_b<<" "<<p.m_c<<endl;;
}


// 类对象 作为 类成员
class A
{
public:
    string p_name;

    A(string name) : p_name(name)
    {
        cout<<"A的构造函数调用"<<endl;
    }

    ~A()
    {
        cout<<"A的析构函数调用"<<endl;
    }
};
class B
{
public:
    A a;
    string name;

    B (string name1,string name2) : a(name1),name(name2)
    {
        cout<<"B的构造函数调用"<<endl;
    }
    // a(name1) 等价于 A a=name1 等价于 A a=A(name1)

    ~B()
    {
        cout<<"B的析构函数调用"<<endl;
    }
}; 
void test04()
{
    B person("abc","xyx");
    cout<<person.name<<" "<<person.a.p_name<<endl;
}


// 静态成员
// 所有对象共享同一份数据
// 编译阶段分配内存
// 类內声明,类外初始化
class f4
{
public:
    static int m_A;

    static void func()
    {
        m_A=1919810;
        cout<<"func()调用 "<<endl;
    }
};
void test05()
{
    f4 p1;
    cout<<p1.m_A<<endl;
    f4 p2;
    p2.m_A=200;
    cout<<p1.m_A<<endl; // 通过对象访问

    cout<<f4::m_A<<endl; // 通过类名访问

    // 静态成员函数
    // 所有对象共享一个函数
    // 静态成员函数只能访问静态成员变量
    // 但是类內普通函数也可以访问静态成员变量

    f4 p3;
    p3.func(); // 通过对象访问
    cout<<114514<<endl;
    f4::func(); // 通过类名访问
    cout<<p1.m_A<<endl;
}
int f4::m_A=100; // 类內声明,类外初始化


// 对象模型
// 只有非静态的成员变量才属于类的对象 (类內函数,静态变量不属于)
// 成员变量和成员函数分开存储
class f5
{
public:

    int m_a; // 4 字节
    static int m_b; // 不占 类 的字节
};
void test06()
{
    f5 p;
    cout<<sizeof p<<endl; 
    // 空类大小是 1 字节
}


// this 指针
// 因为类內函数不属于类 会造成 对象调用函数时 不知道是谁调用
// this 指向 被调用成员属于的 对象
// 形参和类的变量名同名时 可以用 this 区分
// 在非静态成员函数 需要返回 对象 本身 可以直接 return *this
class f6
{
public:
    f6(int age) // 形参和类的变量名同名时
    {
        this->age=age;
        //等价于  (*this).age=age;
    }

    f6& add(f6& p)
    {
        this->age+=p.age;

        return *this;
    }

    int age;
};
void test07()
{
    f6 p1(18);
    cout<<p1.age<<endl; 

    f6 p2(20);
    p2.add(p1).add(p1).add(p1);
    cout<<p2.age<<endl;
}


// 空指针 访问成员函数
class f7
{
public:
    void show1()
    {
        cout<<"show"<<endl;
    }

    void show_age()
    {
        cout<<m_age<<endl;
    }

    int m_age;
};
void test08()
{
    f7* p=NULL;
    p->show1();
    // p->show_age(); 空指针不能访问传入成员的函数
}


// const 修饰成员函数
// 修饰后 是为 常函数
// 不可修改成员属性
// 加上 mutable 后 可以在常函数修改
// const 修饰对象 为 常对象
// 常对象 只能调用 常函数
class f8
{
public:
    // this 的本质 是一个 指针常量 不可修改
    // 相当于 f8* const this
    // 函数末尾加 const 等效于 const f8* const this
    // 成员函数后面加 const 修饰的是 this 指向 让 指针指向的值也不可修改
    void show_a() const
    {
        // m_a=100;
        m_b;
    }
    f8() : m_a(0), m_b(0) {}
    void func(){}

    int m_a;
    mutable int m_b; // 加上 mutable 后 可以被常函数修改
};
void test09()
{
    const f8 p; // 常对象
    // p.m_a=10;
    p.m_b=100;

    p.show_a(); // 常对象 只能调用 常函数
    // p.func();
}


// 全局函数做友元
class f9
{
   friend void vis(f9 &p); // 类內 在类开头声明 全局函数 使得全局函数可以访问私有成员

public:
    f9()
    {
        m_bed="abc";
        m_room="xyz";
    }

    string m_room;

private:
    string m_bed;
};
void vis(f9 &p)
{
    cout<<p.m_room<<endl;
    cout<<p.m_bed<<endl;
}
void test10()
{
    f9 p;
    vis(p);
}

// 类做友元
class build
{
    friend class f10;  // f10 调用 build 在build类前 添加 f10作为友元
public:
    build(); // 类內声明 类外实现

    string m_room;
private:
    string m_bed;
};
// 类外实现成员函数
build::build()
{
    m_bed="abc";
    m_room="xyz";
}
class f10
{
public:
    f10();

    void vis();

    build* building;
};
f10::f10()
{
    building=new build; // 在堆区 创建了一个 build 类型的对象 让 building 指向这个对象的地址
}
void f10:: vis()
{
    cout<<building->m_room<<endl;
    cout<<building->m_bed<<endl;
}
void test11()
{
    f10 p;
    p.vis();
}

// 成员函数做友元
class build2; // 先声明 要被用到其中 private 变量的类
class f11
{
public:
    f11();

    void vis2();

    build2* building;
};
class build2 // 再在主类后实现
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





int main()
{
    // test(); 
    // cout<<endl;

    // test01(); 
    // cout<<endl;

    // test02();
    // cout<<endl;

    // test03();
    // cout<<endl;

    // test04();
    // cout<<endl;

    // test05();
    // cout<<endl;

    // test06();
    // cout<<endl;

    // test07();
    // cout<<endl;

    // test08();
    // cout<<endl;

    // test10();
    // cout<<endl;

    // test11();
    // cout<<endl;

    // test12();
    // cout<<endl;

    Base b[2]; // 这个数组中 每一个元素都是 Base 类型 所以每一个元素都调用一次构造函数
    return 0;
}