#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        unordered_map<int ,int> mp;
        int n; cin>>n;
        for(int i=1;i<=n;i++)
        {
            int x; cin>>x;
            mp[x-i]++;
        }
        
        int ans=0;
        for(auto v:mp) ans=max(ans,v.second);
        
        cout<<ans<<endl;
    }
    
    return 0;
}