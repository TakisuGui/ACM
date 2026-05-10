#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll

void solve()
{
    int n,k; cin>>n>>k;
    
    vector<int> starts, ends;
    for(int i=0; i<n;i++)
    {
        int l,r; cin>>l>>r;
        starts.push_back(l-k);
        ends.push_back(r);
    }

    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    int ans=0;
    int cur=0;
    int j=0; //// 指向ends的指针

    for(int i=0; i<n;i++)
    {
        cur++;
        
        while(j<n && ends[j]<starts[i])
        {
            cur--;
            j++;
        }
        ans=max(ans,cur);
    }

    cout<<ans<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}