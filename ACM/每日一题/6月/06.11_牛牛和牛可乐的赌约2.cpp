#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e3+10;



void solve()
{
   int x,y; cin>>x>>y;

   if( ( (x%3) ^ (y%3) ) != 0) cout<<"yyds\n";
   else cout << "awsl\n";
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}