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
        ll a,b,c;
        cin>>a>>b>>c;
        
        if(c>a+1||c<a-1||c>b+1||c<b-1||a>c+1||a<c-1||a<b-1||a>b+1||b>a+1||b<a-1||b>c+1||b<c-1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }  
    return 0;
}