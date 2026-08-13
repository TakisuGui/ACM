#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e7+7;

vector<int> a(N);
vector<int> b(N);


void solve()
{
    int n,m; cin>>n>>m;

    for(int i=n-1,j=m;i>=0;)
    {
        int k=j;
        while((k&i)!=i) k++;
        for(int r=0;r<=k-j&&i>=0;r++) cout<<(i--)<<" "<<k-r<<endl;

        j=k+1;
    }
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}