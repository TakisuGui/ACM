#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e7+7;

string manacher_ss(string s)
{
    string ss; ss.resize(s.size()*2+1);
    for(int i=0,j=0;i<(s.size()*2+1);i++)
    {
        ss[i] = (i%2==0) ? '#' : s[j++];
    }
    return ss;
}

void solve()
{
    string s; cin>>s;
    string ss=manacher_ss(s);

    vector<int> p(s.size()*2+1);

    int max_len=0;
    for(int i=0,c=0,r=0;i<ss.size();i++)
    {
        int len = (r>i) ? min(p[2*c-i],r-i) : 1;
        while(i+len<ss.size()&&i-len>=0&&ss[i+len]==ss[i-len])
        {
            len++;
        }

        if(len+i>r)
        {
            r=i+len;
            c=i;
        }
        max_len=max(max_len,len);
        p[i]=len;
    }
    cout<<max_len-1<<endl;
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