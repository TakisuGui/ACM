#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n; cin>>n;
    if(n<=2)
    {
        cout<<"No"<<endl;
        return;
    }

    cout<<"Yes"<<endl;

    if((n&(n-1))==0)
    {
        int t=n/4;

        cout<<3*t<<" "<<n<<" "<<5*t<<endl;
    }
    else
    {
        ll even=0; 
        while(n%2==0)
        {
            n/=2;
            even++;
        }

        ll x=(n*n-1)/2;
        ll y=(n*n-1)/2+1;

        while(even--)
        {
            n*=2;
            x*=2;
            y*=2;
        }

        cout<<n<<" "<<x<<" "<<y<<endl;
    }
}


int main()
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