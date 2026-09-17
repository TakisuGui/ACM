#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e6+10;

void solve()
{
    string s; int n;
    cin>>s>>n;

    for(ll i=n;i<s.size()-n;i++) cout<<s[i];
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