#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

vector<int> get_next(string s,int siz)
{
    if(siz==1) return {-1};

    vector<int> next(siz);
    next[0]=-1,next[1]=0;

    int i=2,cn=0;

    while(i<siz)
    {
        if(s[cn]==s[i-1])
        {
            next[i]=cn+1;
            cn++;
            i++;
        }
        else if(cn>0) cn=next[cn];
        else next[i]=0,i++;
    }

    return next;
}

void solve()
{
    string s; cin>>s;
    int n; cin>>n;
    vector<int> next=get_next(s,s.size());
    int ans=0;

    while(n--)
    {
        string text; cin>>text;
        int cur=0,max_cur=0;
        int i=0; // text 中的下标

        while(i<text.size()&&cur<s.size())
        {
            if(text[i]==s[cur]) { i++; cur++; max_cur=max(max_cur,cur); }
            else if(cur==0) i++;
            else cur=next[cur];
        }

        ans+=max_cur;
    }

    cout<<ans<<endl;
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