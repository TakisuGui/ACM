#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e6+10;


void solve()
{
    string c="HelloWorld";
    int x;cin>>x;
    for(int i=0;i<c.size();i++)
    {
        if(i+1==x) continue;
        cout<<c[i];
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