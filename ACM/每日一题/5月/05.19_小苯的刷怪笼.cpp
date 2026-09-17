#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{
    int n,a,k; cin>>n>>a>>k;
    int d=(a-k);

    if(n==1)
    {
        cout<<( (a==k) ? a : -1)<<endl;
        return;
    }

    if(d*2>a||d<n/2)
    {
        cout<<-1<<endl;
        return;
    }
    else
    {
        int x=d-(n-2)/2;
        int y=a-x-n+2;
        cout<<max(x,y)<<" "<<min(x,y)<<" ";
        for(int i=0;i<n-2;i++) cout<<1<<" ";

        cout<<endl;
    }
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}