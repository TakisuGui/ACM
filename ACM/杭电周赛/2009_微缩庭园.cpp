#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;

void solve()
{
    ll n,m; cin>>n>>m;
    if(n%2==1||m%2==1) cout<<(m*n+1)/2<<endl;
    else cout<<(m*n)/2-min(n,m)<<endl;
}

int main()
{
    int size(256<<20);  // 256M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
        solve();
    }
    exit(0);
}