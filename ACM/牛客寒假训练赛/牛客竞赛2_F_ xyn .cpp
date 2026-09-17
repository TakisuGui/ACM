#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        int L=0; ll temple=n;
        while(temple>0)
        {
            L++;
            temple=temple>>1;
        }
        
        ll x=n*(1ll<<L);
        ll y=x+n;
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}