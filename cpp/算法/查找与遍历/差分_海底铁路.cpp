#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

typedef long long ll;

int main()
{
    ll n, m;cin>>n>>m;
    ll a[N]={0};
    ll f[N]={0};

    ll begin;cin>>begin;
    for(ll i=2;i<=m;i++)
    {
        ll dete;cin>>dete;

        if(dete>=begin)
        {
            f[begin]++;
            f[dete]--;
        }
        else{
            f[dete]++;
            f[begin]--;
        }

        begin=dete;
        
    }


    ll cost=0;
    for(ll i=1;i<=n-1;i++)
    {
        a[i]=f[i]+a[i-1];

        ll ai,bi,ci;cin>>ai>>bi>>ci;

        ll small=min(ai*a[i],ci+bi*a[i]);

        cost+=small;
    }

    cout<<cost<<endl;
}


