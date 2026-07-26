#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;

vector<ll> p = {2,3,5,7,11,13,17,19,23,29,31,37};
ll qpow(ll a,ll b,ll c)//(a^b) mod c
{ 
    ll ans=1;
    a%=c;
    while(b)
    {
        if(b&1) ans=(ans*a)%c;
        a=a*a%c;
        b>>=1;
    }
    return ans;
}


template<class T>
inline T read() // 内联函数
{
    T x=0,f=1;
    char ch=0;
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1; // 判断正负号
    for(;isdigit(ch);ch=getchar())  x=(x<<3)+(x<<1)+(ch-'0');
    return x*f;
}

template<class T>
inline void write(T x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}


bool miller_rabin(ll n)
{
    if(n<3||n%2==0) return n==2;

    ll u=n-1,t=0;
    while(u%2==0)
    {
        u/=2;
        t++;
    }

    for(auto a : p)
    {
        if(n==a) return true;
        if(n%a==0) return false;

        ll v=qpow(a,u,n);
        if(v==1) continue;

        ll s=1;
        for(;s<=t;s++)
        {
            if(v==n-1) break;
            v=(v*v)%n;
        }
        if(s>t) return false;
    }
    return true;
}


int main() 
{
    ll t=read<ll>();
    while(t--) 
    {
        ll n=read<ll>();
        if(miller_rabin(n)) puts("Yes");
        else puts("No");
    }
    return 0;
}