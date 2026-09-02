#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{
    string s; cin>>s;
    int sum=0,dex2=0,dex3=0;
    for(auto c : s) 
    {
        sum+=(c-'0');
        if(c-'0'==2) dex2++;
        else if(c-'0'==3) dex3++;
    }

    if(sum%9==0)
    {
        cout<<"YES"<<endl;
        return;
    }

    for(int i=0;i<=min(dex2,9ll);i++)
    {
        for(int j=0;j<=min(dex3,6ll);j++)
        {
            int cur=sum+i*2+j*6;
            if(cur%9==0)
            {
                cout<<"YES"<<endl;
                return;
            }
        }
    }

    cout<<"NO"<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}