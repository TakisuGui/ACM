#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll


void solve()
{
   int a,b,c; cin>>a>>b>>c;

   int l=a+b-1-c;

    string x;
   if(a==1) x="15";
   else x="15"+string(a-2,'0');
   string y=string(b+l,'6');
   string z=string(b+l-1,'6')+"7";

   cout<<x<<" "<<y<<" "<<x<<" "<<z<<endl;
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