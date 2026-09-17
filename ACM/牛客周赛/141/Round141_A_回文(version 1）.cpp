#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=2e5+10;

ll re(ll x)
{
    ll ans=0;

    while(x>0)
    {
        ans+=(x%10);
        ans*=10;
        x/=10;
    }
    ans/=10;

    return ans;
}

void solve()
{
    ll n; cin>>n;

    ll x=sqrt(n);
    while((x+1)*(x+1)<=n) x++;
    while(x*x>n) x--;


    if(x*x != n)
    {
        cout<<"NO"<<endl;
        return;
    }
    
    if(re(x)==x&&re(n)==n) cout<<"YES"<<endl;
    else cout<<"NO"<< endl;
    
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