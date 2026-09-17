#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{
    int n; cin>>n;
    
    if(n==1) 
    {
        cout<<"1"<<endl;
        return;
    }
    else if(n==2)
    {
        cout<<"1 2"<<endl<<"3 4"<<endl;
        return;
    }
    else if(n==3)
    {
        cout<<"1 2 3"<<endl<<"5 4 6"<<endl<<"7 8 9"<<endl;
        return;
    }
    
    cout<<"-1"<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}