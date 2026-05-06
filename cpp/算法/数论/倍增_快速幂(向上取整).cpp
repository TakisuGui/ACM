#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b,c;

ll qpow(ll a,ll b,ll c)
{ 
    ll ans =1;

    while(b)
    {
        if(b&1) ans=(ans*a) %c;
        a=a*a%c;
        b>>=1;
    }
 
}

int main()
{
    cin>>a>>b>>c;

    printf("%lld^%lld mod %lld=%lld",a,b,c,qpow(a,b,c));

}

//ceil(a/b)=floor((a+b-1)/b);