#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

//创建
int q[N],h,t;

//入队
void push(int x){

    t++;
    q[t]=x;
}

//出队
void pop(){

    h++;
}

//查询对头
int front(){

    return q[++h];
}

//查询队尾
int back(){

    return q[t];
}

//判空
bool empty(){
    return t==h;
}

//元素个数
int size(){
    
    return t-h;
}