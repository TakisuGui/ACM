#include<iostream>
using namespace std;

typedef long long LL;

const int N=1e5+10;

int n,q;
LL a[N];
LL f[N];//前缀和数组；
 
int main()
{
    cin>>n>>q;
    
    for(int i=1;i<=n;i++)cin>>a[i];

    for(int i=1;i<=n;i++) f[i]=f[i-1]+a[i];

    for(int p=1;p<=q;p++)
    {
        int l,r;
        cin>>l>>r;

        cout<<f[r]-f[l-1]<<endl;
    }




    return 0;
}