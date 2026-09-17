#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n; cin>>n;
    int dex_0=0,dex_1=0;
    string a; cin>>a;
    
    for(char c:a)
    {
        if(c-'0'==1) dex_1++;
        else dex_0++;
    }
    
    if(dex_1==n)
    {
        cout<<n<<endl;
        return;
    }
    else if(dex_0==n)
    {
        cout<<"0"<<endl;
        return;
    }
    else
    {
        cout<<n-1<<endl;
        return;
    }

}

int main()
{
    int t; cin>>t;
        
    while(t--)
    {
        solve();
    }

    return 0;
}