#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int a[N];
int n;

void insert_sort(){
    for(int i=2;i<=n;i++)
    {
        int temp=a[i];

        int p=i-1;
        while(p>=1&&a[p]>temp){
            a[p+1]=a[p];
            p--;
        }
        a[p+1]=temp;
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