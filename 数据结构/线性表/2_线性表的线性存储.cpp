#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;


template<class T>
class List
{
public:
    virtual bool isempty()=0;
    virtual T getelem(int i)=0;
    virtual int locateelem(T e)=0;
    virtual int Length()=0;
    virtual Status Insert(int i,T e)=0;
    virtual bool Delete(int i,T& e)=0;
    virtual Status Push_back (T e)=0;
};


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
    bool Insert(int i,T e);
    bool Delete(int i,T& e);
    void Union(Sqlist<T>& lb)
    Status Push_back (T e);
    Status Reverse();

    virtual void Inputlist();
    void Outputlist();
};

// 1. 初始化和销毁
template<class T>
Sqlist<T>:: Sqlist()
{
    elem=new T[N];
    length=0;
    listsize=N;
}
template<class T>
Sqlist<T>:: ~Sqlist()
{
    delete[] elem;
};


// 2. 插入元素
template<class T>
bool Sqlist<T>:: Insert(int i,T e)
{
    T* p;
    if(i<1||i>length+1) return false;

    if(length>=listsize)
    {
        T* newbase=new T[listsize+N];
        if(!newbase) return false;
        p=elem; elem=newbase;

        for(int i=0;i<length;i++) elem[i]=p[i];
        listsize+=N;
    }

    T* q=&(elem[i-1]);
    for(int p=&elem[length-1];p>=q;p--) *(p+1)=*p;
    *q=e;
    length++;
    return true;
}


// 3. 删除元素
template<class T>
bool Sqlist<T>:: Delete(int i,T& e)
{
    T* p; T* q;
    if(i<1||i>length) return false;

    p=&elem[i-1];
    e=*p;
    for(T* i=p;i<elem+length-1;i++) *i=*(i+1);
    length--;
    return true;
}


// 4. 合并
template<class T>
void Sqlist<T>:: Union(Sqlist<T>& lb)
{
    int lb_len=lb.length;
    int e;

    for(int i=1;i<=lb_len;i++)
    {
        e=lb.getelem(i);
        if(this->locateelem(e)==0) this->Insert(e);
    }
}


// 5. 归并
template<class T>
void Merge(Sqlist<T> la,Sqlist<T> lb,Sqlist<T>& lc)
{
    int i=1,j=1,k=0;
    int la_len=la.length,lb_len=lb.length;
    int ai,bj;

    while((i<=la_len)&&(j<=lb_len))
    {
        ai=la.getelem(i);
        bj=lb.getelem(j);

        if(ai<=bj) lc.Insert(++k,ai),i++;
        else lc.Insert(++k,bj),j++;
    }

    while(i<=la_len)
    {
        ai=la.getelem(i);
        lc.Insert(++k,ai);
        i++;
    }
    while(j<=lb_len)
    {
        bj=lb.getelem(j);
        lc.Insert(++k,bj);
        j++;
    }
}
