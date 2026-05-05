#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=1e5+10;

ll qpow(ll a,ll b,ll c)//(a^b) mod c
{ 
    ll ans =1;
    a%=c;
    while(b)
    {
        if(b&1) ans=(ans*a)%c;
        a=a*a%c;
        b>>=1;
    }
    return ans;
}

int main()
{
    ll a,b,c,d,mod; cin>>a>>b>>c>>d>>mod;

    if(c*d==0||a*b==0)
    {
        cout<<"0"<<endl;
        return  0;
    }
    
    c*=d;
    cout<<1ll*qpow(a,c,mod)*qpow(b,c,mod)%mod<<endl;

    return 0;
}