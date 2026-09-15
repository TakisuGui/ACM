#include<bits/stdc++.h>
using namespace std;


template<class T>
class List
{
public:
    virtual bool isempty()=0;
    virtual T getelem(int i)=0;
    virtual int locateelem(T e)=0;
    virtual int Length()=0;
    virtual Status Insert(int i,T e)=0;
    virtual Status Delete(int i,T& e)=0;
    virtual Status Push_back (T e)=0;
};

template<class T>
class Node
{
public:
    T data;
    Node<T>* next;
};

template<class T>
class linkedlist: public List<T>
{
public:
    Node<T>* head;
public:
    linkedlist();
    ~linkedlist();

    bool isempty();
    T getelem(int i);
    int locateelem(T e);
    int Length();
    virtual bool Insert(int i,T e);
    virtual bool Delete(int i,T& e);
    virtual bool Pushback(T e);

    virtual void Outputlist();
    bool Inputlist();
    bool Inputlist_R();
    void Union(linkedlist<T>& lb);
};


// 1. 初始化和销毁
template<class T>
linkedlist<T>:: linkedlist()
{
    head=new Node<T>;
    head->data=0;
    head->next=nullptr;
}

template<class T>
linkedlist<T>:: ~linkedlist()
{
    Node<T>* p;
    while(head!=nullptr)
    {
        p=head;
        head=head->next;
        delete p;
    }
}


// 2. 获取单链表中指定元素位置
template<class T>
T linkedlist<T>:: getelem(int i)
{
    T e;
    Node<T> *p;
    p=head->next;
    int j=1;
    while(p&&j<i)
    {
        p=p->next; j++;
    }

    if(!p||j>i) return e;
    return p->data;
};


// 3. 插入元素
template<class T>
bool linkedlist<T>:: Insert(int i, T e)
{
    Node<T>* p; Node<T>* s;
    p=head;
    int j=0;
    while(p&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(!p||j>i-1) return false;

    s=new Node<T>;
    s->data=e; s->next=p->next;
    p->next=s;
    return true;
}


// 4. 删除元素
template<class T>
bool linkedlist<T>:: Delete(int i, T& e)
{
    Node<T>* p; Node<T>* q;
    p=head;
    int j=0;
    while(p&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(!p||j>i-1) return false;

    q=p->next;
    p->next=q->next;
    e=q->data;
    delete q;
    return true;
}

// 5.1 逆序建表(头插)
template<class T>
bool linkedlist<T>:: Inputlist_R()
{
    Node<T>* p;
    int n; cin>>m;
    for(int i=0;i<n;i++)
    {
        p=new Node<T>;
        if(!p) return false;
        cin>>p->data;
        p->next=head->next;
        head->next=p;
    }
    return true;
};

// 5.2 正序建表(尾插)
template<class T>
bool linkedlist<T>:: Inputlist()
{
    Node<T> *p; Node<T>* last;
    last=head;
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        p=new Node<T>;
        cin>>p->data;
        (*last).next=p;
        last=p;
    }
    (*last).next=nullptr;
    return true;
}

// 6. 合并
template<class T>
void linkedlist<T>:: Union(linkedlist<T>& lb)
{
    int lb_len=lb.Length();
    int e;

    for(int i=1;i<=lb_len;i++)
    {
        e=lb.getelem(i);
        if(this->locateelem(e)==0) this->Insert(e);
    }
}