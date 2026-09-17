#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;cin>>t;
    while(t--)
    {
        int n,k;cin>>n>>k;int a[n+1];
        for(int i=1;i<=n;i++) cin>>a[i];
        int max_dex=k+a[1];
        for(int i=2;i<=n;i++)
        {
            max_dex=max(max_dex,a[i]+a[i-1]);
        }
        max_dex=max(max_dex,k+a[n]);
        cout<<max_dex<<endl;
    }
    
    return 0;
    
}