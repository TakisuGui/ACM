#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int long long
const int N=1e5+10;

vector<pair<ll,ll>> a(N);

void solve()
{
    ll n,s; cin>>n>>s;
    for(int i=1;i<=n;i++)
    {
        int x,y,v; cin>>x>>y>>v;
        int length=x*x+y*y;
        a[i]={length,v};
    }

    sort(a.begin()+1,a.begin()+1+n);

    bool pass=false; ll have=0; double r2=0;
    for(int i=1;i<=n;i++)
    {
        have+=a[i].second;
        r2=a[i].first;
        if(have>=s)
        {
            pass=true;
            break;
        }
    }

    if(!pass)
    {
        cout<<"-1"<<endl;
        return;
    }
    else
    {
        r2=pow(r2,0.5);
        printf("%.10lf\n",r2);
    }

}


signed main()
{
    solve();

    return 0;
}