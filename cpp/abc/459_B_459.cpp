#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e6+10;

int get_digit(char ch) 
{
    if (ch >= 'a' && ch <= 'c') return 2;
    if (ch >= 'd' && ch <= 'f') return 3;
    if (ch >= 'g' && ch <= 'i') return 4;
    if (ch >= 'j' && ch <= 'l') return 5;
    if (ch >= 'm' && ch <= 'o') return 6;
    if (ch >= 'p' && ch <= 's') return 7;
    if (ch >= 't' && ch <= 'v') return 8;
    if (ch >= 'w' && ch <= 'z') return 9;
    return 0;
}


void solve()
{
    int n; cin>>n;
    while(n--)
    {
        string s; cin>>s;
        cout<<get_digit(s[0]);
    }
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