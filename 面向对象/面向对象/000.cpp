#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

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
    dowork2(p3);  // 应用后 & 不再会创造一个新对象 所以不会调用 拷贝构造函数
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
    // p->show_age(); 空指针不能访问需要传入值的成员函数
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




// 多态
// 静态多态 : 函数重载 和 运算符重载       早绑定 编译阶段确定函数地址
// 动态多态 : 派生类和虚函数实现运行时多态  晚绑定 运行阶段确定函数地址
class f37
{
public:
    // 虚函数
    // 父类还是允许这个虚函数访问,
    // 如果是 子类转化为的父类 就会访问子类的 同名函数
    virtual void speak()
    {
        cout<<114514<<endl;
    }
};
class f38: public f37
{
public:
    // 子类 重写 父类虚函数
    virtual void speak()
    {
        cout<<1919810<<endl;
    }
};
class f39: public f37
{
public:
    // 子类 重写 父类虚函数
    void speak()
    {
        cout<<1010101<<endl;
    }
};
// 如果是 & 不拷贝绑定到原对象 访问 f38 里面继承的 f37
// 如果无 & 创建新对象 发生切片 子类部分被切掉 仅有从父类继承部分
// 使用地址晚绑定 也即是 访问子类转化为的父类时 直接访问其子类的函数
void dospeak(f37& p) // f37& p = p1   父类 子类 间允许相互转换
{
    p.speak();
}
void test26()
{
    f38 p1;
    dospeak(p1);
    f39 p2;
    dospeak(p2);
}
void test27()
{
    // 32位是4  64位是8
    cout<<sizeof(f37)<<endl;
    cout<<sizeof(f38)<<endl;
    // 有虚函数后 父类类內 存在一个 vfptr (虚函数指针)
    // vfptr 指向 vftable (虚函数表)
    // 表内记录虚函数地址  子类完全继承父类的 虚函数地址 所以指向父类的虚函数
    // 子类重写 父类 虚函数 后
    // 子类中的 虚函数表 会覆盖替换成 子类的虚函数地址
    // 当父类的指针 指向 子类对象的时候 发生多态(子类转化成父类被调用父类中同名函数)
    // 即使 子类没有重写父类虚函数 发生继承后 还是会继承父类的 虚函数指针
    // 所以 无论是否重写 子类大小都会有 一个从父类继承的虚函数指针大小(8)
}


// 纯虚函数 和 抽象类
// 可以把 虚函数 改成 纯虚函数 
// virtual 返回值类型 函数类型 (参数列表) = 0;
// 有了 纯虚函数的类 是 抽象类
// 抽象类 无法实例化 对象  必须在子类中 重写父类的虚函数 才能实例化子类
class f40
{
public :
    virtual void func()=0;
};
class f41: public f40
{
public:
    void func()
    {
        cout<<114514<<endl;
    }
};
void test28()
{
    //f40 p;
    f41 p2;
    f40* p3=new f41;
    p3->func();
}



// 虚析构 和 纯虚析构
// 父类指针指向一个子类对象时 会出现 子类转父类指针
// 最后在调用父类的析构函数时
// 造成 只有父类部分被销毁了 但是子类特有的成员变量没有被释放
class f42
{
public:
    virtual void speak() = 0;

    f42()
    {
        cout<<"父类构造函数调用"<<endl;
    }

    // virtual ~f42()
    // {
    //     cout<<"父类析构函数调用"<<endl;
    // }

    // 必须既要 声明 又要 实现
    virtual ~f42() = 0; // 等于 0 的目的 是让父类变成抽象类 无法实例化对象
};
// 子类析构执行完后 会自动强制地 向上调用父类的析构函数
// 所以必须 让父类虚构函数有内容
f42::~f42()
{
    cout<<"父类纯析构函数调用"<<endl;
}
class f43: public f42
{
public: 
    virtual void speak()
    {
        cout<<*name<<endl;
    }

    f43(string s): name(new string(s))
    {
        cout<<"子类构造函数调用"<<endl;
    }

    ~f43()
    {
        if(name!=NULL)
        {
            cout<<"子类析构函数调用"<<endl;
            delete name;
            name=NULL;
        }
    }

    string* name;
};
void test29()
{
    f42* p1=new f43("Tom");
    p1->speak();
    delete p1;    // 堆区 必须手动删除 才会调用 delete
    cout<<endl<<endl;

    f43 p2("1919810"); // 本身这里 已经正常父子类 给构造 析构一次
    p2.~f43(); // ~f43 被父类覆盖 所以 调用父类的析构函数
}


// 文件操作
// 包含 文件流 头文件 <fstream>
// 分为 文本文件 和 二进制文件
// 文件流包括三个类 ofstream写_输出流  ifstream读_输入流  fstream读写

// 文件打开方式
// ios::open 读文件
// ios::out  写文件
// ios::ate  初始位置:文件尾
// ios::app  追加方式写文件
// ios::trunc   先删除(如果存在),再创建
// ios::binary  二进制形式
// 可以配合使用 利用 | 操作符
// ios::binary | ios::out   用二进制形式写文件

// 写文件
void test30()
{
    // 创建输出流对象
    ofstream p;

    // 指定打开方式
    p.open("text114514.exe",ios::out);

    // 写入
    p<<"114514"<<endl;

    p.close();
}

// 读文件
void test31()
{
    ifstream p;

    p.open("text114514.exe",ios::in);

    if(!p.is_open())
    {
        cout<<"文件打开失败"<<endl;
        return;
    }

    string s1;
    while(p>>s1)
    {
        cout<<s1<<endl;
    }

    char s2[1024]={0};
    while(p.getline(s2,1024))
    {
        cout<<s2<<endl;
    }

    string s3;
    while(getline(p,s3))
    {
        cout<<s3<<endl;;
    }

    char c;
    while( (c=p.get()) != EOF ) // end of file
    {
        cout<<c;
    }
}

// 二进制写文件
class f44
{
public:
    char name[64];
    int m_age;
};
void test32()
{
    ofstream p;

    p.open("f43.txt",ios::out | ios::binary);

    f44 data={"1919810",18};
    p.write( (const char*)& data , sizeof(f44) );

    p.close();
}
// 二进制读文件
void test33()
{
    ifstream p;

    p.open("f43.txt",ios::in | ios::binary);

    if(!p.is_open())
    {
        cout<<"文件打开失败"<<endl;
        return;
    }

    f44 get_;
    p.read( (char*)& get_,sizeof(f44) );

    cout<<get_.name<<" "<<get_.m_age<<endl;

    p.close();
}



// 函数模板
template<typename T>
void myswap(T& a,T&b)
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




int main()
{
    // test(); 
    // cout<<endl;

    test01(); 
    cout<<endl;

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

    // test13();
    // cout<<endl;

    // test14();
    // cout<<endl;

    // test15();
    // cout<<endl;

    // test16();
    // cout<<endl;

    // test17();
    // cout<<endl;

    // test18();
    // cout<<endl;

    // test19();
    // cout<<endl;

    test20();
    cout<<endl;

    // test21();
    // cout<<endl;

    // test22();
    // cout<<endl;

    // test23();
    // cout<<endl;

    // test24();
    // cout<<endl;

    // test25();
    // cout<<endl;

    // test26();
    // cout<<endl;

    // test27();
    // cout<<endl;

    // test28();
    // cout<<endl;

    // test29();
    // cout<<endl;

    // test30();
    // cout<<endl;

    // test31();
    // cout<<endl;

    // test32();
    // cout<<endl;

    // test33();
    // cout<<endl;
    
    // test34();
    // cout<<endl;

    // test35();
    // cout<<endl;

    // test36();
    // cout<<endl;

    // test37();
    // cout<<endl;

    // test38();
    // cout<<endl;

    // test39();
    // cout<<endl;

    // test40();
    // cout<<endl;

    // test41();
    // cout<<endl;

    // test42();
    // cout<<endl;

    // test43();
    // cout<<endl;

    // test44();
    // cout<<endl;

    // test45();
    // cout<<endl;

    

    Base b[2]; // 这个数组中 每一个元素都是 Base 类型 所以每一个元素都调用一次构造函数
    return 0;
}