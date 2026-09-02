#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b,x;

int main()
{
    cin>>a>>b>>x;

    ll group=x/3;
    ll suplus=x%3;

    if(a*3<=b) cout<<(1ll)*x*a<<endl;
    else cout<<min(((1ll)*group*b+suplus*a),((1ll)*(group+1)*b))<<endl;

    return 0;
}