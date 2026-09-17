#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"


ll gcd(ll a,ll b)
{
    if (b==0) return a;
    else return gcd(b,a%b);
}

void solve()
{
    ll a,b; cin>>a>>b;

    if(a==1&&b==1)
    {
        cout<<"1"<<endl;
        return;
    }
    
    ll g=gcd(a,b);

    if(g!=1)
    {
        cout<<"0"<<endl;
        return;
    }
    else
    {
        ll d=abs(a-b);
        ll temp=d;

        if(d==1)
        {
            cout<<"-1"<<endl;
            return;
        }

        ll ans=1e15+10;
        for(ll i=2;i*i<=temp;i++)
        {
            while(d%i==0)
            {
                d/=i;
                ans=min(ans,(1ll*i-a%i)%i);
            }
        }
        if(d>1) ans=min(ans,(d-a%d)%d);


        cout<<ans<<endl;
    }
}



int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}