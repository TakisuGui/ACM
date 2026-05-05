#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        ll n,x,y,z,m; cin>>n>>x>>y>>z>>m;
        cout<<((1ll)*x+y+z-m-n)/2<<endl;
    }

    return 0;
}