#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;


void solve()
{
    string s; cin>>s;

    if(s[0]!='o'&&s[0]!='O') {cout<<"NO"; return;}
    if(s[1]!='v'&&s[1]!='V') {cout<<"NO"; return;}
    if(s[2]!='o'&&s[2]!='O') {cout<<"NO"; return;}

    cout<<"YES";
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