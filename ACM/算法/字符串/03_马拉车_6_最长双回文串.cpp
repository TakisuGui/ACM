#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e6+10;
const int MOD=19930726;

string get_ss(string s,int n)
{
    string ss; ss.resize(2*n+1);

    for(int i=0,j=0;i<2*n+1;i++)
    {
        if(i%2==0) ss[i]='#';
        else ss[i]=s[j++];
    }
    return ss;
}


vector<int> get_p(string s,int n)
{
    vector<int> p(n);

    for(int i=0,r=0,c=0,len;i<n;i++)
    {
        len=1;
        if(r>i) len=min(r-i,p[2*c-i]);
        while(i+len<n&&i-len>=0&&s[i-len]==s[i+len]) len++;

        if(i+len>r) r=i+len,c=i;
        p[i]=len;
    }
    return p;
}


void solve()
{
    string s; cin>>s;
    int n=s.size(),t=s.size()*2+1;
    string ss=get_ss(s,n);
    vector<int> p=get_p(ss,t);

    vector<int> left(t,0),right(t,0);

    for(int i=0,j=0;i<t;i++)
    {
        while(i+p[i]>j)
        {
            left[j]=j-i;
            j+=2;
        }
    }
    for(int i=t-1,j=t-1;i>=0;i--)
    {
        while(i-p[i]<j)
        {
            right[j]=i-j;
            j-=2;
        }
    }

    int ans=0;
    for(int i=2;i<=t-3;i+=2)
    {
        ans=max(ans,left[i]+right[i]);
    }
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