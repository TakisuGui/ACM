#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string get_from(string s)
{
    string t;
    for(char c:s)
    {
        t+=c;
        if(t.size()>=4 && t.substr(t.size()-4)=="(xx)") //t.end_with("(xx)")
        {
            t.pop_back();
            t.pop_back();
            t.pop_back();
            t.pop_back();
            t+="xx";
        }
    }

    return t;
}

void solve()
{
    string a,b; cin>>a>>b;

    cout<<(get_from(a)==get_from(b) ? "Yes" : "No")<<endl;
}


int main()
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