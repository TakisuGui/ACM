#include<bits/stdc++.h>
using namespace std;

const int N=60;
typedef long long ll;

ll f[N];
int n;

int main()
{
    // cin>>n; f[1]=1;f[2]=2;f[3]=4;

    // for(int i=4;i<=n;i++) f[i]=f[i-1]+f[i-2]+f[i-3];

    // cout<<f[n]<<endl;

    cin>>n;

    ll a=1,b=2,c=4;ll t;

    for(int i=4;i<=n;i++)
    {
        t=a+b+c;
        a=b,b=c,c=t;
    }

    if(n==1) cout<<a<<endl;
    else if(n==2) cout<<b<<endl;
    else if(n==3) cout<<c<<endl;
    else 
    cout<<t<<endl;


    return 0;
}