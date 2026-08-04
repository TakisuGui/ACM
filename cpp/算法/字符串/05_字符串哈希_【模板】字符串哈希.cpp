#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=10001;
const int base=499;

vector<int> nums(N);

int v(char c) 
{
    if (c>='0'&&c<='9') return c-'0'+1;
    else if(c>='A'&&c<='Z') return c-'A'+11;
    else return c-'a'+37;
}

ull value(string s)
{
    ull ans=v(s[0]);
    for(int i=1;i<s.size();i++) ans=(ans*base)+v(s[i]);
    return ans;
}

void solve()
{
    int n; cin>>n;

    for(int i=0;i<n;i++)
    {
        string s; cin>>s;
        nums[i]=value(s);
    }

    int cnt=0;
    sort(nums.begin(),nums.begin()+n);
    int ans=1;
    for(int i=1;i<n;i++) if(nums[i]!=nums[i-1]) ans++;

    cout<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}