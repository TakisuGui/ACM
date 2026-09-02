#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int MOD=998244353;

void solve()
{
    string a,b; cin>>a>>b;
    ll n=a.size();
    ll m=b.size();
    
    ll sumA=0,powsumA=0;
    ll p10=1;

    for(int i=a.size()-1;i>=0;i--)
    {
        int val=a[i]-'0';
        sumA=(sumA+(ll)val*p10)%MOD;
        p10=(p10*10)%MOD;
    }

    ll sumB=0,powsumB=0;
    p10=1;

    for(int i=b.size()-1;i>=0;i--)
    {
        int val=b[i]-'0';
        sumB=(sumB+(ll)val*p10)%MOD;
        p10=(p10*10)%MOD;
    }
    
    ll ans=(sumA*(m%MOD)%MOD+sumB*(n%MOD)%MOD)%MOD;
    cout<<ans%MOD<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;;
    while(t--)
    {
        solve();
    }

    return 0;
}