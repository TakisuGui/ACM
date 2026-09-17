#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e7+7;


void solve()
{
    int n; cin>>n;
    string a,b; cin>>a>>b;

    int odd_a=0,odd_b=0,even_a=0,even_b=0;

    for(int i=0;i<n;i++)
    {
        if(a[i]=='1')
        {
            if(i%2==0) even_a++;
            else odd_a++;
        }
        if(b[i]=='1')
        {
            if(i%2==0) even_b++;
            else odd_b++;
        }
    }

    cout<<(odd_a==odd_b&&even_a==even_b ? "YES" : "NO")<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}