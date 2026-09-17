#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=2e5+10;

void solve()
{
    int n,m; cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> cnt(m+1,0);
    int total=0;
    int min_len=n+1;
    int L=0;

    for(int R=0;R<n;R++)
    {
        if(a[R]<=m)
        {
            if(cnt[a[R]]==0) total++;

            cnt[a[R]]++;
        }

        while(total==m) 
        {
            min_len=min(min_len,R-L+1);

            if(a[L]<=m)
            {
                cnt[a[L]]--;
                if(cnt[a[L]]==0) total--;
            }
            L++;
        }
    }

    if(min_len>n) cout<<"-1"<<endl;
    else cout<<min_len-m<<endl;
    
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
