#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

vector<int> a(N+10);
void ini()
{
    a[1]=1;
    for(int i=2;i<=N;i++) a[i]=a[i-1]+i;
}

void solve()
{
    int n; cin>>n;
    int sum=0;
    bool pass=true;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        sum+=x;
        if(sum<a[i]) pass=false;
    }

    cout<<(pass ? "YES" : "NO")<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    ini();
    while(t--)
    {
        solve();
    }

    return 0;
}
