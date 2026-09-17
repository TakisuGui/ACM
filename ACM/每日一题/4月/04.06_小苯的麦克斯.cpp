#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;
int a[N];

void solve()
{
    int n; cin>>n; 
    for(int i=1;i<=n;i++) cin>>a[i];
    int max_dex=a[1],max_pos=1;
    int ans=-1;

    for(int i=2;i<=n;i++)
    {
        if(a[i]>max_dex)
        {
            max_dex=a[i];
            max_pos=i;
        }
    }

    if(max_pos-1>=1&&max_pos+1<=n)
    {
        if(a[max_pos-1]==0&&a[max_pos+1]==0)
        {
            if(max_dex==1) ans=max_dex-2;
            else ans=max_dex-1;
        }
        else ans=max_dex;
    }
    else if(max_pos-1>=1&&max_pos+1>n)
    {
        if(a[max_pos-1]==0)
        {
            if(max_dex==1) ans=max_dex-2;
            else ans=max_dex-1;
        }
        else ans=max_dex;
    }
    else
    {
        if(a[max_pos+1]==0)
        {
            if(max_dex==1) ans=max_dex-2;
            else ans=max_dex-1;
        }
        else ans=max_dex;
    }

    cout<<ans<<endl;
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