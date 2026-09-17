#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll


void solve()
{
    string s; cin>>s;
    string ans="";
    vector<string> q;
    for(int i=0;i<s.size();i++)
    {
        ans+=s[i];
        if((s[i]-'0')%2==0) 
        {
            q.push_back(ans);
            ans="";
        }
    }

    sort(q.begin(),q.end(),[](const string& a,const string& b)
    {
        if(a.size()!=b.size()) return a.size()<b.size();
        return a<b;
    });

    for(auto v : q) cout<<v<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}