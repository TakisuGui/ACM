#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=3e5+10;

void solve()
{
    int x1,y1,r1,x2,y2,r2;
    cin>>x1>>y1>>r1>>x2>>y2>>r2;

    int dis= (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    int mn=abs(r1-r2);
    int mx=(r1+r2);

    cout<< ((dis<=mx*mx)&&(dis>=mn*mn) ? "Yes" : "No")<<endl;;
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