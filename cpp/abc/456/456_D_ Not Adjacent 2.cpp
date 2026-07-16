#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;
const int MOD=998244353;

void solve()
{
    string s; cin>>s;
    ll a=0,b=0,c=0;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='a') a=(a+(b+c+1))%MOD;
        else if(s[i]=='b') b=(b+(a+c+1))%MOD;
        else c=(c+(a+b+1))%MOD;
    }

    cout<<(a+b+c)%MOD<<endl;
}

signed main()
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