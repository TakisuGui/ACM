#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n; cin>>n;
    vector<ll> a(n); int ans=1,temp=1;
    for(int i=0;i<n;i++) cin>>a[i];
    
    for(int i=1;i<n;i++)
    {
        if(abs(a[i]-a[i-1])<=1)
        {
            temp++;
        }
        else
        {
            ans=max(temp,ans);
            temp=1;
        }

        ans=max(ans,temp);
    }

    cout<<ans<<endl;

    return 0;
}