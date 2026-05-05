#include<bits/stdc++.h>
using namespace std;

const int N=1e4+10;

int a[N],b[N],x_lenth[N],y_lenth[N];
int n;
int x,y;

int find()
{
    for(int i=n;i>=1;i--)
    {
        if(x>=a[i]&&y>=b[i]&&x<=a[i]+x_lenth[i]&&y<=b[i]+y_lenth[i]){
            return i;
        }
    }

    return -1;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>x_lenth[i]>>y_lenth[i];

    cin>>x>>y;

    cout<<find()<<endl;

    return 0;
}