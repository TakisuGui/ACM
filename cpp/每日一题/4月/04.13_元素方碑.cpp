#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=2e5+10;
int a[N]; ll sum;

void solve()
{
    int n; cin>>n; sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }

    if(sum%n!=0)
    {
        cout<<"NO"<<endl;
        return;
    }

    ll avg=sum/n;
    ll odd=0,even=0;
    for(int i=1;i<=n;i+=2) odd+=a[i];
    for(int i=2;i<=n;i+=2) even+=a[i];

    if(odd!=avg*((n+1)/2)||even!=avg*(n/2)) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}