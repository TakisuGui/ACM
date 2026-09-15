#include<bits/stdc++.h>
#include "1_List.h" 
using namespace std;
const int N=1e3+10;


template<class T>
class Sqlist: public List<T>
{
public:
    T* elem;
    int length;
    int listsize; // 可以容纳最大元素个数
public:
    Sqlist();
    ~Sqlist();

    bool isempty();
    T getelem(int i);
    int locateelem(T e);
    int Length();
    virtual bool Insert(int i,T e);
    virtual bool Delete(int i,T& e);
    void Union(Sqlist<T>& lb)
    virtual bool Push(T e);
    Status Reverse();

    virtual void Inputlist();
    virtual void Outputlist();
};



template<class T>
class sorted_sqlist: public Sqlist<T>
{
    friend istream& operator>>(istream& cin,sorted_sqlist<T>& s);
    friend ostream& operator<<(ostream& cout,sorted_sqlist<T>& s);
public:
    sorted_sqlist()=default;
    ~sorted_sqlist()=default;

    bool isempty();
    T getelem(int i);
    bool Insert(int i,T e);
    bool Delete(int i,T& e);
    bool Push(T e);

    void Inputlist();
    void Outputlist();

    void Merge(sorted_sqlist<T>& la,sorted_sqlist<T>& lb);
};


// 1. 插入
template<class T>
bool sorted_sqlist<T>:: Push(T e)
{
    T* p; T*q;
    for(p=this->elem;p<this->elem+this->length;p++)
    {
        if(e<*p) break;
    }

    for(q=this->elem+this->length-1;q>=p;q--) *(q+1)=*q;
    *p=e;
    (this->length)++;
    return true;
}


// 2. 归并
template<class T>
void sorted_sqlist<T>:: Merge(sorted_sqlist<T>& la,sorted_sqlist<T>& lb)
{
    T* pa; T* pb; T* pc; T* pa_last; T* pb_last;
    pa=la.elem,pb=lb.elem;

    this->listsize=this->length=la.length+lb.length;
    delete[] this->elem;
    pc=this->elem=new T[this->listsize];
    pa_last=la.elem+la.length-1;
    pb_last=lb.elem+lb.length-1;

    while(pa<=pa_last&&pb<=pb_last)
    {
        if(*pa<*pb) *pc++=*pa++;
        else *pc++=*pb++;
    }

    while(pa<=pa_last) *pc++=*pa++;
    while(pb<=pb_last) *pc++=*pb++;
}

// 3. 输入&输出
template<class T>
istream& operator>>(istream& cin,sorted_sqlist<T>& s)
{
    int n; cin>>n;
    s.length=0;
    for(int i=0;i<n;i++)
    {
        T x; cin>>x;
        s.Push(x);
    }
    return cin;
}
template<class T>
ostream& operator<<(ostream& cout,sorted_sqlist<T>& s)
{
    for(int i=0;i<s.length;i++)
    {
        cout<<s.elem[i]<<" ";
    }
    cout<<endl;
    return cout;
}