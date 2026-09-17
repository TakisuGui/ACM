#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int a[N];
int n;

//随机选择基准元素
int get_random(int left,int right){

    return a[rand() % (right-left+1) +left];
}


void quick_sort(int left,int right){


    if(left>=right)return;

    //1.选择一个基准元素
    int p=get_random(left,right);

    //2.数组分三块
    int l=left,r=right;
    int i=left;

    while(i<=r){
    if(a[i]<p){
        swap(a[l],a[i]);
        l++;i++;
    }
    else if(a[i]==p){
        i++;
    }
    else{
        swap(a[i],a[r]);
        r--;
    }

    }

    //3.递归
    quick_sort(left,l-1);
    quick_sort(r+1,right);

}


int main()
{
    cin>>n;

    srand(time(0));

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

        quick_sort(1,n);

        for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";

    }


    return 0;
}