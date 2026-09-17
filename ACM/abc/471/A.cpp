#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
const int N=2e5;
const int MOD=1e7+7;



void solve()
{
    int a,b; cin>>a>>b;

    if(a+b==9||a-b==9||a*b==9||(a%b==0&&a/b==9)) cout<<"Nine"<<endl;
    else cout<<"Nein"<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}