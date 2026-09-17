#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF=1e18;

void solve()
{
    ll n; cin>>n;
    ll p=INF;
    ll temp=n;

    while(temp%2==0) temp/=2;

    if(temp>1)
    {
        ll small=temp;
        for(ll i=3;i*i<=temp;i+=2)
        {
            if(temp%i==0)
            {
                small=i;
                break;
            }
        }
        p=small;
    }

    ll q=INF;
    if(n%4==0) q=4;

    ll k=min(q,p);

    cout<<n/k<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if(cin>>t)
    {
        while(t--)
        {
            solve();
        }
    }
    return 0;
}