#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

int a[]={-1,2,3,5,5,7,7,11,11,11};

void solve()
{
   string s; cin>>s;

   cout<<a[s[0]-'0']<<string(s.size()-1,'0')<<" ";
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