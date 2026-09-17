#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

int main()
{
    cin>>n;
    vector<int> a(n),pre(n);
    int s=0;
    for(int i=0;i<n;i++)
        cin>>a[i], s^=a[i],pre[i]=s;
    
    ll ans=0;
    int cnt=0,cur=0;
    for(int i=0;i<n-1;i++)
    {
        cur^=a[i];
        if(cur==0) ans+=cnt;
        if(cur==s) cnt++;
    }
    
    cout<<ans<<endl;
    
    return 0;
}