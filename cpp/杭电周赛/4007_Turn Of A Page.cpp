#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int a[N];

void solve()
{
    int n,s; cin>>n>>s; bool pass=false; unordered_map<int,int> mp;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }

    if(mp[0]+mp[s]==n&&mp[s]>=1) pass=true;
    if(s==0&&mp[0]==n) pass=true;


    cout<<(pass ? "YES":"NO")<<endl;
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