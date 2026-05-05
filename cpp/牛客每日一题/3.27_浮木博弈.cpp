#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n; cin>>n;
    int cnt_1=0; bool in=true;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        if(x==1&&in) cnt_1++;
        else
        in=false;
    }

    if(in)
    {
        if(cnt_1%2==1) cout<<"Alice\n";
        else cout<<"Bob\n";
    }
    else
    {
        if(cnt_1%2==1) cout<<"Bob\n";
        else cout<<"Alice\n";
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