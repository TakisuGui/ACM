#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{
    int n,k; cin>>n>>k;
    vector<int> things(n);
    string has;
    vector<double> price(n);

    for(int i=0;i<n;i++) cin>>things[i];
    cin>>has;

    for(int i=0;i<n;i++) price[i]=(has[i]=='1' ? (double)things[i]*0.95 : (double)things[i]);

    sort(price.begin(),price.end());

    double cost=0,i;
    for(i=0;i<n;i++)
    {
        if(cost+price[i]>k) break;
         
        cost+=price[i];
    }

    cout<<i<<endl;
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