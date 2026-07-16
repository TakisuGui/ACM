#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{   
    int n,k; cin>>n>>k;
    // len+(n-2)+2len=k
    int len=2+k-n;

    string s;
    s+='a';
    s+=string(len,'b');
    s+='c';

     string t="abc";
    for(int i=0;s.size()<n;i++) s+=t[i%3];

    cout<<s<<endl;
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