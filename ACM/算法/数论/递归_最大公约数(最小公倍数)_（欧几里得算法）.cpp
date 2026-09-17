#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5+10;

int n;
ll a[N];

ll gcd(ll a,ll b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
    return a*b*gcd(a,b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ll g;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

        if(i==1)  g=a[i];
        else g=gcd(g,a[i]);
    }

    sort(a+1,a+1+n);

    ll s=(a[n]/g-n)%3;

    if(s==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}