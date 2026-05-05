#include<bits/stdc++.h>
using namespace std;

const int N =1e5+10;
int e[N],ne[N],h,id;
int mp[N];

//头插
void push_front(int x){
    id++;
    e[id]=x;
    mp[x]=id;

    ne[id]=ne[h];
    ne[h]=id;
}

//遍历
void print(){

    for(int i=ne[h];i;i=ne[i]){
        cout<<e[i]<<' ';
        
    }
 cout<<endl<<endl;
}

//插入
void insert(int p,int x){
    id++;
    e[id]=x;
    mp[x]=id;

    ne[id]=ne[p];
    ne[p]=id;

}


//按值查找
int find(int x){
    return mp[x];
}

//删除
void erase(int p){
    ne[p]=ne[ne[p]];
}



int main(){
for(int i=1;i<=5;i++){
    push_front(i);
    print();
}

insert(2 ,89);
print();
insert(2,100);
print();
erase(mp[4]);
print();

return 0;
}