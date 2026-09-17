#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e3+10;


int t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;
        ll a[n+1][m+1];
        memset(a,0,sizeof a);
        vector<ll> pre(n+2,0);
        ll ans=0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;;j++)
            {
               if(j==m)
               {
                pre[i]=a[i][j];
                break;
               }

               if(a[i][j]<0) ans+=abs(a[i][j]);
               else
               {
                   if(a[i+1][j]>=a[i][j+1]||i>=n) a[i][j+1]+=a[i][j];
                   else a[i+1][j]+=a[i][j];
               }
            }

        }

        for(int i=1;;i++)
        {
             if(i==n)
            {
                ans+=abs(pre[i]);
                break;
            }

            if(pre[i]<=0) ans+=abs(pre[i]);
            else pre[i+1]=pre[i+1]+pre[i];
        }


        cout<<ans<<endl;
    }

    return 0;
}