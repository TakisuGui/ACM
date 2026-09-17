#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve()
{
    int n,a,b; cin>>n>>a>>b;
    int ans=0;
    
    for(int i=0;i<=n;i++)
    {
        int h=i,g=n-i;
        int cnt=0;
        while(h>=a||g>=b)
        {
            if(h>=a&&(g<b||a<=b))
            {
                int t=h/a;
                h-=t*a;
                g+=t;
                cnt+=t;
            }
            else
            {
                int t=g/b;
                g-=t*b;
                h+=t;
                cnt+=t;
            }
        }

        ans=max(cnt,ans);
    }

    cout<<ans+n<<endl;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}