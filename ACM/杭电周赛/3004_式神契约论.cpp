#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;

ll f[N];

void solve()
{ 
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;i++) f[i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j+=i)
        {
            f[j]++;
            f[i]++;
        }
    }
    for(int i=1;i<=n;i++) f[i]-=2;
    sort(f+1,f+1+n);
    cout<<f[n-k+1]<<endl;
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