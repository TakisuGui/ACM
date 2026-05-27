#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

int a[N];

void solve()
{
    int n; cin>>n;
    deque<int> q;
    for(int i=1;i<=n;i++) q.push_back(i);
    for(int i=1;i<=n;i++) cin>>a[i];

    bool pass=true;
    for(int i=1;i<=n;i++)
    {
        int top=q.front();
        int last=q.back();

        if(a[i]==top) q.pop_front();
        else if(a[i]==last) q.pop_back();
        else
        {
            pass=false;
            break;
        }
    }

    cout<<(pass ? "YES" : "NO")<<endl; 
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