#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e3+10;

ll qpow(int a,int b,int MOD)
{
    ll ans=1;
    a%=MOD;
    while(b>0)
    {
        if(b&1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}

bool is_prime(long long n)
{
    if (n<2) return false;
    if (n==2||n==3) return true;
    if (n%2==0) return false;

    int bases[]={2,3,5,7,11,13,17,19,23,29,31,37};
    int d=n-1;
    while(d%2==0) d/=2;

    for(auto a : bases)
    {
        if(n==a) return true;
        if(qpow(a,d,n)!=1)
        {
            ll t=d;
            bool prime=false;
             while(t<n-1) 
             {
                if (qpow(a,t,n)==n-1) 
                {
                    prime=true;
                    break;
                }
                t*=2;
            }
            if (!prime)  return false;
        }
    }
    return true;
}

void solve()
{
    int n; cin>>n;
    cout<<(is_prime(n) ? "Yes" : "No")<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}