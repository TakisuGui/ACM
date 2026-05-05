#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n; cin>>n;
    string text; cin>>text;
    deque<char> q;

    bool left=false;

    for(char c:text)
    {
        if(c>='a'&&c<='z'&&left) q.push_front(c);
        else if(c>='a'&&c<='z'&&!left) q.push_back(c);
        else if(c=='!')
        {
            if(left) left=false;
            else left=true;
        }
        else if(c=='-')
        {
            if(q.size()==0) continue;

            if(!left) q.pop_back();
            else q.pop_front();
        }
    }

    if(q.size()!=0)
    {
        string result;
        for(char c:q) result+=c;
        cout<<result<<endl;
    }
    else cout<<"Empty"<<endl;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}