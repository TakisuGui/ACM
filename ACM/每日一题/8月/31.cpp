#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e18;
const int MOD=998244353;

    
void solve()
{
    int n; cin>>n;
    string s; cin>>s;
    stack<pair<int,int>> q;

    for(int i=0;i<s.size();i++)
    {
        if(!q.empty())
        {
            auto [c,id] = q.top();
            if(s[i]>='A'&&s[i]<='Z')
            {
                int cur=s[i]-'A';
                if(id==1&&c+cur==25&&cur<c) q.pop();
                else q.push({cur,1});
            }
            else
            {
                int cur=s[i]-'a';
                if(id==0&&c+cur==25&&cur>c) q.pop();
                else q.push({cur,0});
            }
        }
        else
        {
            if(s[i]>='A'&&s[i]<='Z') q.push({s[i]-'A',1});
            else q.push({s[i]-'a',0});
        }
    }

    cout<<q.size()<<endl;
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