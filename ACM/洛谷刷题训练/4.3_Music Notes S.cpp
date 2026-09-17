#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;

int n,q;
ll f[N];

int main()
{
    cin>>n>>q;

    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        f[i]=f[i-1]+x;
    }

    while(q--)
    {
        int t;cin>>t;

        int l=0,r=n;
        while(l<=r)
        {
            int mid=(l+r)/2;

            if(f[mid]>t) r=mid-1;
            else l=mid+1;
        }

        cout<<l<<endl;
    }

    return 0;
}