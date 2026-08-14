#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e18;
const int MOD=1e7+7;

int poison(int k,int c)
{
    return c*(1+k)*k/2+k;
}

int normal(int b,int m,int p) // p = c*k
{
    if(m>=p) return m*b+(p+1)*p/2;
    else return m*b+m*p-(m-1)*m/2;
}

void solve()
{
    int x,a,b; cin>>x>>a>>b;
    int c=(a-1);

    int ans=(x+b-1)/b;
    if(ans==1)
    {
        cout<<1<<endl;
        return;
    }

    int kmax=sqrt(2*x)+2;
    for(int k=1;k<=kmax;k++)
    {
        if(k>=ans) break;

        ll e=poison(k,c);
        if(e>=x)
        {
            ans=min(ans,k);
            if(k>=ans) break;
            continue;
        }

        int rem=x-e;
        int p=c*k;

        int l=0,r=rem,has=rem+1;
        while(l<=r)
        {
            int mid=(l+r)/2;

            if(normal(b,mid,p)>=rem)
            {
                has=mid;
                r=mid-1;
            }
            else l=mid+1;
        }

        ans=min(ans,k+has);
    }
    cout<<ans<<endl;
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