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
    int x;cin>>x;
    if(x==1)
    {
        cout<<"YES"<<endl;
        cout<<"1"<<endl;
    }
    else if(x==3)
    {
        cout<<"YES"<<endl;
        cout<<"1 2 3"<<endl;
    }
    else cout<<"NO"<<endl;
    }
    
    return 0;
}