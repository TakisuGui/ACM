#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


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