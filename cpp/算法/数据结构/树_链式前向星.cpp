#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int h[N],e[2*N],ne[2*N],id;

int n;

//b头插到a所在链表后面
void add(int a,int b){
    id++;
    e[id]=b;

    ne[id]=h[a];
    h[a]=id;

}


int main(){

    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;

        add(a,b);add(b,a);
    }


    return 0;
}