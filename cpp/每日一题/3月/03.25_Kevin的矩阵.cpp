#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;

int a[N];
int n,m,k;

int num_cost(int new_m)
{
    int cur_ans=n;
    for(int i=1;i<=new_m;i++)
    {
        int cnt=0;
        for(int j=i;j<=n;j+=new_m) if(a[j]!=k) cnt++;

        cur_ans=min(cur_ans,cnt);
    }

    return cur_ans;
}

void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=n;

    for(int d=0;d<ans;d++)
    {
        int i=m+d;
        if(i>n) continue;   
        ans=min(ans,d+num_cost(i));
        i=m-d;
        if(i<=0) continue;
        ans=min(ans,d+num_cost(i));
    }

    cout<<ans<<endl;
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