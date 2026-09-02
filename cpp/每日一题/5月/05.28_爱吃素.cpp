#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e11+10;

bool prime(int a)
{
    if(a==1)  return false;
    for(int i=2;i*i<=a;i++)
    {
        if(a%i==0) return false;
    }

    return true;
}

void solve()
{
    int a,b; cin>>a>>b;
    bool ans;

    if(a==1&&b==1) ans=false;
    else if(a==1&&prime(b)) ans=true;
    else if(b==1&&prime(a)) ans=true;
    else ans=false;

    cout<<(ans ? "YES" : "NO")<<endl;
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