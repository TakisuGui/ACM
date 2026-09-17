#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

int sum[27][N],s1[27][N],s2[27][N];

void solve()
{
    int n,q; cin>>n>>q;
    string text; cin>>text; text=" "+text;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=25;j++)
        {
            sum[j][i]=sum[j][i-1]+(text[i]-'a'==j);
            s1[j][i]=s1[j][i-1]+sum[j][i];
            s2[j][i]=s2[j][i-1]+sum[j][i]*sum[j][i-1];
        }
    }

    ll ans;
    int l,r,x; 
    
    while(q--)
    {
        cin>>l>>r>>x; ans=0;

        if(x==1)
        {
            ans=r-l+1;
        }
        else if(x==2)
        {
            for(int j=0;j<=25;j++)
            {
                int c=sum[j][r]-sum[j][l-1];
                ans+=c*(c-1)/2;
            }
        }
        else
        {
            for(int j=0;j<=25;j++)
            {
                ans+=sum[j][r]*(s1[j][r-1]-(l >= 2 ? s1[j][l-2] : 0));
                ans+=sum[j][l-1]*(s1[j][r]-s1[j][l-1]);
                ans-=(r-l+1)*(sum[j][r]*sum[j][l-1]);
                ans-=(s2[j][r]-s2[j][l-1]);
            }
        }

        cout<<ans<<endl;
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