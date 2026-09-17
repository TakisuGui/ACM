#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=2e5;
const int MOD=1e9+7;

void solve()
{
    int n; cin>>n;
    string s; int has=0; cin>>s;

    for(int i=1;i<n;i++)
    {
        if(s[i]^s[i-1]) has++;
    }

    if(n>4)
    {
        if(has==0) cout<<2<<endl;
        else if(has==1||has==2) cout<<1<<endl;
        else cout<<0<<endl;
    }
    else
    {
        if (s == "1111")    cout << 2 << '\n';
        else if (s == "0111")    cout << 1 << '\n';
        else if (s == "1011")    cout << 1 << '\n';
        else if (s == "1101")    cout << 1 << '\n';
        else if (s == "1110")    cout << 1 << '\n';
        else if (s == "1100")    cout << 2 << '\n';
        else if (s == "0011")    cout << 2 << '\n';
        else if (s == "1010")    cout << 0 << '\n';
        else if (s == "0101")    cout << 0 << '\n';
        else if (s == "0110")    cout << 2 << '\n';
        else if (s == "1001")    cout << 2 << '\n';
        else if (s == "0001")    cout << 1 << '\n';
        else if (s == "0010")    cout << 1 << '\n';
        else if (s == "0100")    cout << 1 << '\n';
        else if (s == "1000")    cout << 1 << '\n';
        else if (s == "0000")    cout << 2 << '\n';
    }
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}