#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=1e5+10;
const int MOD=1e9+7;

vector<int> get_next(string s,int siz)
{
    if(s.size()==1) return {-1};

    vector<int> next(siz+1);
    next[0]=-1,next[1]=0;

    int i=2,cn=0;
    while(i<=siz)
    {
        if(s[i-1]==s[cn])
        {
            next[i]=cn+1;
            i++;
            cn++;
        }
        else if(cn>0) cn=next[cn];
        else next[i]=0,i++;
    }

    return next;
}

void solve()
{
   int n; cin>>n;
   string s; cin>>s;

   vector<int> next=get_next(s,n);

   cout<<n-next[n]<<endl;
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
