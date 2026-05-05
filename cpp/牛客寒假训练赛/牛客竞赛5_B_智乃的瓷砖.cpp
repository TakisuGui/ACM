#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll f[17];

ll rev(ll x)
{
    ll res=0;
    while(x)
    {
        res=res*10+(x%10);
        x/=10;
    }

    return res;
}

void ini()
{
    f[0]=1;
    for(int i=1;i<=16;i++) f[i]=f[i-1]*10;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if((i+j)%2==0) cout<<'/';
            else cout<<'\\';
        }
        cout<<endl;
    }
    
}