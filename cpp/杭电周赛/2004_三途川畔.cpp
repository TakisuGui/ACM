#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n,k; cin>>n>>k;
    if(n==2)
    {
        cout<<"2 "<<2+k<<endl;
        return;
    }
    else
    {
        cout<<"1";
        for(int i=1;i<=n-3;i++) cout<<" 1";
        cout<<" 2 "<<n+k<<endl;
    }
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