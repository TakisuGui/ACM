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
        int n;cin>>n;
        vector<long long> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        long long sum=0;
        long long maxdex=1;
        long long maxp=a[1];
        for(int i=2;i<=n;i++)
        {
            maxp=max(maxp,a[i]);
            if(maxp==a[i]) maxdex=i;
        }
        
        if(maxdex==1) sum=a[n]+a[1]*(n-1);
        else if(maxdex==n) sum=a[1]+a[n]*(n-1);
        else sum=a[1]+a[n]+maxp*(n-2);
        
        cout<<sum<<endl;
        
    }
    
    return 0;
    
}