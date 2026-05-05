#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=2e5+10;

ll a[N];

void solve()
{
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];

    sort(a+1,a+1+n);

    int max_in=1;
    int j=2;

    for(int i=1;i<=n;i++)
    {
        while(j<=n&&a[j]-a[i]<=k) j++;

        max_in=max(max_in,j-i);
    }

    double ans=(double)(max_in)*1.0/n;

    printf("%.10lf\n",ans);
}

int main()
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