#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=5e5+10;

int n;
vector<int> a(N);
vector<int> temp(N);

int f(int l,int r)
{
    if(l==r) return 0;

    int mid=(l+r)/2;
    int ans=f(l,mid)+f(mid+1,r);

    for(int i=mid,j=r;i>=l;i--)
    {
        while(a[j]>=a[i]&&j>=mid+1) j--;
        ans+=(j-mid);
    }

    int cnt=l,i=l,j=mid+1;
    while(i<=mid&&j<=r)
    {
        if(a[j]>=a[i])
        {
            temp[cnt++]=a[i];
            i++;
        }
        else
        {
            temp[cnt++]=a[j];
            j++;
        }
    }
    while(i<=mid) temp[cnt++]=a[i++];
    while(j<=r) temp[cnt++]=a[j++];

    for(int t=l;t<=r;t++) a[t]=temp[t];

    return ans;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<f(1,n)<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}