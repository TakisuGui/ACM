#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=100+10;

int a[N],b[N];

void solve()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        a[i]=x;
    }
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        if(a[x]!=i)
        {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
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