#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e6+10;
const int MOD=998244353;


void solve()
{
    int a=8100178706957568;

    for(int i=11;i<=36;i++)
    {
        int cur=a; bool pass=true;
        while(cur>0)
        {
            int b=cur%i;
            cur/=i;
            if(b>9)
            {
                pass=false;
                break;
            }
        }
        if(pass)
        {
            cout<<i<<endl;
            return;
        }
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