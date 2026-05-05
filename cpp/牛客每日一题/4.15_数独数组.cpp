#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
int mp[10];

void solve()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        mp[x]++;
    }
    bool pass=true;

    sort(mp+1,mp+1+9);
    if(mp[9]-mp[1]>1) pass=false;

    cout<<(pass ? "YES" : "NO")<<endl;
}

int main()
{
    solve();
    return 0;
}