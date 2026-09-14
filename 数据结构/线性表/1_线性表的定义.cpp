#include<bits/stdc++.h>
using namespace std;


template<class T>
class List
{
public:
    virtual bool isempty()=0;
    virtual T getelem(int i)=0;
    virtual int locateelem(T e)=0;
    virtual int length()=0;
    virtual Status Insert(int i,T e)=0;
    virtual Status Delete(int i,T& e)=0;
    virtual Status Push_back (T e)=0;
};

