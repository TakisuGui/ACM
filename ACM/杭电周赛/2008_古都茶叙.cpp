#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;

void solve()
{
    int n; cin>>n;
    ll pre[2*N]; pre[0]=0;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<=2*n;i++) pre[i]=pre[i-1]+a[(i-1)%n];

    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> heap_small;

    int ans=-1;
    for(int i=1;i<=n;i++) heap_small.push({pre[i],i});
    for (int k = 1; k <= n; k++) {
        while (!heap_small.empty() && heap_small.top().second < k)
        {
            heap_small.pop();
        }

        if (heap_small.top().first - pre[k - 1] >= 0)
        {
            cout << k << "\n"; 
            return;
        }

        if (k < n)
        {
            heap_small.push({pre[n + k], n + k});
        }
    }

    cout<<ans<<endl;
}

int main()
{
    int size(256<<20);  // 256M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
        solve();
    }
    exit(0);
}