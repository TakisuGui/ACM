#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve()
{
    int n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
 
    map<int, int> cnt;
    ll ans=0;
    int l=0;
 
    for(int r=0; r<n;r++)
    {
        cnt[a[r]]++;
 
        while (cnt.size() > 2||(cnt.size() == 2 && cnt.rbegin()->first-cnt.begin()->first>1))
        {
            cnt[a[l]]--;
            if (cnt[a[l]] == 0) cnt.erase(a[l]);
            l++;
        }
 
        ans+=(ll)(r-l+1);
    }
 
    cout<<ans<<"\n";
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}