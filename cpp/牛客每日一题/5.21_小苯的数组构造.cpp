#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;


void solve()
{
    int n,x,y; cin>>n>>x>>y;

    if((x&y)!=y)
    {
        cout<<"NO"<<endl;
        return; 
    }

    if(n==1)
    {
        if(x==y) cout<<"YES"<<endl<<x<<endl;
        else cout<<"NO"<<endl;
        return;
    }

    if(n%2==0 && x==y)
    {
        int lb=x&-x;
        if(lb==x){ cout<<"NO"<<endl; return;}

        cout<<"YES"<<endl;
        for(int i=1;i<=n-2;i++) cout<<x<<" ";
        cout<<lb<<" "<<(lb^x)<<endl;
        return;
    }

    cout<<"YES"<<endl;
    for(int i=1;i<=n-1;i++) cout<<x<<" ";
    cout<<( n%2==0 ? y^x : y)<<endl;
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