#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        
        map<int,int> last;
        ll s=0,ans=0;
        
        for(int i=0;i<n;i++)
        {
            int pre=last[a[i]];
            s=s+(i+1)-pre;
            ans=ans+s*(n-i);
            last[a[i]]=i+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}