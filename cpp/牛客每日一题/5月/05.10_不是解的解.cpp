#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

int a[N],b[N],c[N];

void solve()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];

    int ans; bool pass=true;
    for(int j=1;j<=100;j++)
    {
        ans=rand()%(ll)1e6;
        pass=true;
        for(int i=1;i<=n;i++)
        {
            if(ans*ans*ans+ans*ans*a[i]+ans*b[i]+c[i]==0)
            {
                pass=false;
                break;
            }

            if(pass)
            {
                cout<<ans<<endl;
                return;
            }
        }
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