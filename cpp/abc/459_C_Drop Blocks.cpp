#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=3e5+10;

int a[N];
int c[N];

void solve()
{
    int n,q,t,x,mn=0;
    cin>>n>>q;
    for(int i=0;i<q;i++)
    {
        cin>>t>>x;
        if(t==1)
        {
            a[x]++;
            c[a[x]]++;
            if(c[a[x]]==n) mn=a[x];
        }
        else if(t==2)
        {
            if(mn+x>q) cout<<0<<endl;
            else cout<<c[mn+x]<<endl;
        }
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