#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int a[N];
int n;


//while版本
void down1(int parent,int len)
{
    int child = parent*2;

    while(child<=len){
 
        //找到最大的孩子
        if(child+1<=len&&a[child+1]>a[child]){
            child++;
        }

        if(a[parent]>=a[child])return;

        swap(a[parent],a[child]);

        parent=child;
        child=parent*2;
        
    }
}


//递归版本
void down2 (int parent,int len)
{
    int child=parent*2;

    if(child>len)return;

    if(child+1<=len&&a[child]<a[child+1]){
        child++;
    }

    if(a[parent]>a[child])return;

    swap(a[parent],a[child]);

    down2(child,len);
}


void heap_sort(){
    //建堆
    for(int i=n/2;i>=1;i--)
    {
        down2(i,n);
    }

    //排序
    for(int i=n;i>=1;i--)
    {
        swap(a[i],a[1]);

        down2(1,i-1);
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

        heap_sort();

        for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";

    }


    return 0;
}