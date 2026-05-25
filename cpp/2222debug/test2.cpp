#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

int n,m;

void solve()
{
    cin>>n;
    vector<char> A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    cin>>m;
    vector<char> B(m);
    for(int i=0;i<m;i++) cin>>B[i];

    vector<pair<char, char>> C;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            C.push_back({A[i],B[j]});
    
    for(auto [a,b] : C) cout<<'<'<<a<<","<<b<<'>'<<endl;
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