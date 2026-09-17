#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t; cin>>t;
    int a[200010];
    while(t--)
    {
        int n; cin>>n;
        
        if(n>=4)
        {
            for(int i=1;i<=n;i++) cin>>a[i]; cout<<"YES"<<endl;
        }
        else if(n==1)
        {
            for(int i=1;i<=n;i++) cin>>a[i]; cout<<"YES"<<endl;
        }
        else if(n==2)
        {
            int x,y; cin>>x>>y; if(y-x==1) cout<<"YES"<<endl; else cout<<"NO"<<endl;
        }
        else
        {
            int a,b,c; cin>>a>>b>>c;
            if(b==2) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    
    return 0;
}