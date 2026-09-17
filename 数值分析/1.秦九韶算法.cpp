#include<bits/stdc++.h>
using namespace std;

void solve()
{
    cout<<"请输入非负整数次数"<<endl;
    int n; cin>>n;
    vector<long double> a(n+1);
    cout<<"请由低次到高次输入系数"<<endl;
    for(int i=0;i<=n;i++) cin>>a[i];

    cout<<"请输入求值点 x0"<<endl;
    long double x0; cin>>x0;

    long double ans=a[n];
    for(int i=n-1;i>=0;i--) ans=ans*x0+a[i];
    cout<<fixed<<setprecision(10)<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}