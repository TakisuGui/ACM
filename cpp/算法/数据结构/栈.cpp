#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

//创建栈
int stk[N],n;


//进栈
void  push(int x){

    n++;
    stk[n]=x;
}


//出栈
void pop(){

    n--;
}

//查找栈顶元素
int top(){

    return stk[n];
}

//判断为空栈
bool empty(){

    return n==0;
}

//查询有效元素个数
int size(){

    return n;
}


int main(){
    for(int i=1;i<=10;i++){
        push(i);
    }

    //判断是否为空栈
    while(!empty())//while(size())
    {
        cout<<top()<<endl;
        pop();
    }

    return 0;
}