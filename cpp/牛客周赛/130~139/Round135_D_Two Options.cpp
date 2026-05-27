#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll a[N];

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n; ll sum=0; ll pass=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        
        ll ave=sum/n;
        if(ave>0&&sum%n!=0) ave++;
        
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            if(ave>a[i]) ans+=(ave-a[i]);
        }
        
        cout<<ans<<endl;
    }

    return 0;
}