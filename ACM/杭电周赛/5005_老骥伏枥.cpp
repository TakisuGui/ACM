#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=15;

void solve()
{
    int n; cin>>n;
    cout<<__builtin_popcountll(n^1)<<endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}
