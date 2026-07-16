#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

int a[N];
int gap[N];


void solve()
{
    int n; cin>>n;
    int total=0;
    int ave=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        total+=a[i];
    }

    if(total%n!=0)
    {
        cout<<"NO"<<endl;
        return;
    }
    else ave=total/n;

    for(int i=1;i<=n;i++) gap[i]=a[i]-ave;

    
    int sum=gap[1]; int sum_max=gap[1];int sum_min=gap[1];
    for(int i=2;i<=n;i++)
    {
        sum+=gap[i];
        sum_max=max(sum_max,sum);
        sum_min=min(sum_min,sum);
    }

    cout<<(sum_max-sum_min<=1 ? "YES" : "NO")<<endl;
}

signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}