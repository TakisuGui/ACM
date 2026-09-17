#include<bits/stdc++.h>
using namespace std;


const int N=1e5+10;

int a[N];
int n;

void insert_sort(){
    for(int i=n;i>1;i--){

        bool flag=false;

        for(int j=1;j<i;j++){
            if(a[j]>a[j+1]){

                swap(a[j],a[j+1]);
                flag=true;

            }
        }

        if(flag==false)return;
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