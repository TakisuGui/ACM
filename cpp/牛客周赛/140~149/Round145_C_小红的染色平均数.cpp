#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{   
    int n; cin>>n;
    vector<int> a(n+1);
    string color;
    int sum=0,sumred=0,r=0;

    for(int i=0;i<n;i++) cin>>a[i],sum+=a[i];
    cin>>color;
    for(int i=0;i<n;i++) if(color[i]=='0') sumred+=a[i],r++;


    if((r*sum%n)!=0) {cout<<-1<<endl; return;}
    cout<<abs(sumred-r*sum/n)<<endl;
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