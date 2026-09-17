#include<bits/stdc++.h>
using namespace std;
#define endl "\n"


// 文件操作
// 包含 文件流 头文件 <fstream>
// 分为 文本文件 和 二进制文件
// 文件流包括三个类 ofstream写_输出流  ifstream读_输入流  fstream读写

// 文件打开方式
// ios::in 读文件
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