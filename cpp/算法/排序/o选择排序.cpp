#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int a[N];
int n;

void insert_sort(){

    int q;

    for(int i=1;i<n;i++){

        int min=a[i];
        int min_dex=i;

        //找到这之后的最小元素
    for( q=i+1;q<=n;q++)
    {
        if(min>a[q]){
            min=a[q];
            min_dex=q;
        }
        
    }

    //交换
    // int temp=a[i];
    // a[i]=a[min_dex];
    // a[min_dex]=temp;
    swap(a[i],a[min_dex]);

    }
}
   


int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

        insert_sort();

        for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";

    }


    return 0;
}