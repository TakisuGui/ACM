#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;

void solve()
{
    int n; cin>>n;
    int a[N];
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);

    int ans=1; int last=a[1];
    for(int i=2;i<=n;i++)
    {
        if(a[i]-last>=ans)
        {
            ans++;
            last=a[i];
        }
    }

    cout<<ans<<endl;
    
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}