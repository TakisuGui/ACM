#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int n;
int a[N];


int main(){
    cin>>n;

    for(int i=1;i<=n;i++)cin>>a[i];

    for(int st=0;st<= (pow(2,n)-1) ;st++)
    {
        cout<<"{";

        for(int p=1;p<=n;p++){
            
            if((st>>(p-1))&1)cout<<a[p]<<" ";
        }
        
        cout<<"}";
        
        cout<<endl;
    }

    return 0;
}

