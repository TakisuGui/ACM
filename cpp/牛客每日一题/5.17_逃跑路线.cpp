#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{
   int n; cin>>n;
    int x=0;

    while(n--)
    {
        string a; cin>>a;
        int t=a.size();
        int num=a[t-1]-'0';

        x+=(num%2);
    }

    cout<<(x&1)<<endl;

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