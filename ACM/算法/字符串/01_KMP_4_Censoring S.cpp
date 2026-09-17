#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=1e6+10;
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
    string s1,s2; cin>>s1>>s2;
    int n=s1.size(),m=s2.size();
    int x=0,y=0; 

    vector<int> next=get_next(s2,m);
    vector<int> stack1(N),stack2(N);
    int siz=0;

    while(x<n)
    {
        if(s1[x]==s2[y])
        {
            stack1[siz]=x;
            stack2[siz]=y;
            siz++;
            x++;
            y++;
        }
        else if(y==0)
        {
            stack1[siz]=x;
            stack2[siz]=-1;
            siz++;
            x++;
        }
        else
        {
            y=next[y];
        }

        if(y==m)
        {
            siz-=m;
            y= siz>0 ? (stack2[siz-1]+1) : 0;
        }
    }

    for(int i=0;i<siz;i++) cout<<s1[stack1[i]];
    cout<<endl;
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