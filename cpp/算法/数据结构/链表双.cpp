#include<bits/stdc++.h>
using namespace std;


const int N=1e5 +10;

// 创建双链表
int e[N],pre[N],ne[N],mp[N],id,h;

//头插
int  push_front(int x){

    //创建新的节点
    id++;
    e[id]=x;

    //将新节点pre和ne修改
    ne[id]=ne[h];
    pre[id]=h;
    mp[x]=id;

    //修改头指针ne和哨兵位下一个节点的pre
    pre[ne[id]]=id;
    ne[h]=id;
}

//遍历
int print(void){

    for(int i=ne[h];i;i=ne[i]){
        cout<<e[i]<<" ";
    }
    cout<<endl<<endl;
}

//按值查找
int find(int x){

    return mp[x];
}


//任意位置之后插入
int insert_behind(int p,int x){
    //创建新节点
    id++;
    e[id]=x;
    mp[x]=id;

    //将新节点pre和ne修改
    ne[id]=ne[p];
    pre[id]=p;

    //修改p位置指针ne和p位置位下一个节点的pre
    pre[ne[id]]=id;
    ne[p]=id;
}

//任意位置之前插入
int insert_front(int p,int x){

    //创建新节点
    id++;
    e[id]=x;
    mp[x]=id;

    //将新节点pre和ne修改
    ne[id]=p;
    pre[id]=pre[p];

    //修改p位置指针pre和p位置位上一个节点的ne
    ne[pre[p]]=id;
    pre[p]=id;
}

//删除任意位置
int erase(int p){

    //修改前一节点指向后一节点
    ne[pre[p]]=ne[p];

    //修改后一节点指向前一节点
    pre[ne[p]]=pre[p];
}


 int main(){

    for(int i=1;i<=5;i++){
        push_front(i);
      //print();
    }

   //cout<<find(3);
   //insert_behind(2,45);
   //insert_behind(mp[4],48);
   //insert_front(2,22);
   //insert_front(3,33);
   //insert_front(4,44);
   //erase(mp[4]);
     print();
   
    return 0;
 }