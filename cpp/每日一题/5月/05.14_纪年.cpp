#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{
    int n;
    while(cin>>n)
    {
        int d=n-2018;

        int x1=( ( (d%10)+10)%10 +5 )%10;
        int x2=( ( (d%12)+12)%12 +11)%12;

        if(x1==0) x1=10;
        if(x2==0) x2=12;

        cout<<x1<<" "<<x2<<endl; 
    }
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