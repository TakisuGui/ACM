#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=2e5+10;

int a[N];
int s[N];

void solve()
{
    int n; cin>>n; ll sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]; sum+=a[i];
    }


    ll remain=a[n]; s[n]=a[n];
    for(int i=n-1;i>=1;i--)
    {
        s[i]=min(a[i],s[i+1]);
        remain+=s[i];
    }

    int same=1,mx=1;
    for(int i=2;i<=n;i++)
    {
        if(s[i]==s[i-1]) same++;
        else mx=max(mx,same),same=1;

        mx=max(mx,same);
    }

    cout<<sum-remain+(mx-1)<<endl;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}