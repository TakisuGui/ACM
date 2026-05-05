#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n" 

int main()
{
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==1) cout<<"-1"<<endl;
    sort(a.begin(),a.end());
    
    int mid=(n+1)/2-1;
    int m=a[mid];
    int less=0,big=0,equa=0;
    for(auto x:a)
    {
        if(x<m) less++;
        else if(x>m) big++;
        else equa++;
    }
    
    if(equa==n)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    int ans=2e9;
    if(less>0) ans=min(ans,n-2*less);
    if(big>0)  ans=min(ans,2*(less+equa)-n+1);
    
    cout<<ans<<endl;
    
    return 0;
}