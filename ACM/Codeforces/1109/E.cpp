#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{
    int n,q; cin>>n>>q;
    string s; cin>>s;

    vector<int> pre(n,0);
    for(int i=0;i<n-1;i++) pre[i+1]=pre[i]+(s[i]==s[i+1] ? 1 : 0);

    while(q--)
    {
        int l,r,k; cin>>l>>r>>k; l--; r--;
        if(l==r)
        {
            cout<<"YES"<<endl;
            continue;
        }

        int c=pre[r]-pre[l];
        int min_t=(c+1)/2;

        cout<<(min_t<=k ? "YES" : "NO")<<endl;
    }
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