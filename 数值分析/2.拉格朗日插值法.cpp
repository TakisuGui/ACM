#include<bits/stdc++.h>
using namespace std;

void solve()
{
    cout<<"请输入点的数量"<<endl;
    int n; cin>>n;
    vector<long double> x(n),y(n);
    cout<<"请输入点的坐标"<<endl;
    for(int i=0;i<n;i++) cin>>x[i]>>y[i];
    cout<<"请输入求值点 x0"<<endl;
    long double x0; cin>>x0;

    long double ans=0.0;
    for(int i=0;i<n;i++)
    {
        long double li=(long double)1.0;
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            li*=(x0-x[j])/(x[i]-x[j]);
        }
        ans+=y[i]*li;
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}