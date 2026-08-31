#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e7+7;

using namespace std;

int query(int u,int v,int d) 
{
    if(u==v) return d == 0 ? 1 : 0;
    cout<<"? "<<u<< " "<<v<<" "<<d<<endl;
    cout.flush();
    int res; cin>>res;

    if (res==-1) exit(0);
    return res;
}

void solve() 
{
    int n; cin >> n;

    int A=1;
    int max_d1=0;
    for (int i=2;i<=n;i++) 
    {
        while(query(1,i,max_d1+1)) 
        {
            max_d1++;
            A = i;
        }
    }

    int B=1;
    int D=max_d1;
    for (int i=2; i<=n;i++) 
    {
        if (i==A) continue;
        while (query(A,i,D+1)) 
        {
            D++;
            B=i;
        }
    }

    cout<<"! "<<A<<" "<<B<<" "<<D<<endl;
    cout.flush();
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